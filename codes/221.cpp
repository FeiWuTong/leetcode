/*
 * Approach: DP (similar to #85)
 * Time complexity: O(n^2)   || 12.49% (56 ms)
 * Space complexity: O(n)  || 5.04% (12.1 MB)
 */
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if (!matrix.size()) return 0;
        int m = matrix.size(), n = matrix[0].size(), sides = 0, pre, len;
        vector<int> h(n + 1, 0);
        h[n] = -1;
        for (int i = 0; i < m; i++) {
            stack<int> s;
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == '0') h[j] = 0;
                else h[j]++;
            }
            for (int j = 0; j <= n;) {
                if (s.empty() || h[j] >= h[s.top()]) s.push(j++);
                else {
                    pre = s.top();
                    s.pop();
                    if (h[pre] > sides) {
                        if (s.empty()) len = j;
                        else len = j - 1 - s.top();
                        if (len > sides) sides = min(h[pre], len);
                    }
                }
            }
        }
        return sides * sides;
    }
};
/*
 * Approach: DP
 * Time complexity: O(n^2)   || 38.68% (40 ms)
 * Space complexity: O(n)  || 31.45% (10.9 MB)
 * Note: dp records max square sides at matrix[i][j], dp[i][j] = min(dp[i-1][j-1], dp[i-1][j], dp[i][j-1]) + 1 
 */
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if (!matrix.size()) return 0;
        int m = matrix.size(), n = matrix[0].size(), sides = 0, pre;
        vector<int> dp(n, 0);
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                // last -> dp[i-1][j]
                int last = dp[j];
                // first row / col must be 1 or 0
                if (!i || !j || matrix[i][j] == '0') {
                    dp[j] = matrix[i][j] - '0';
                } else {
                    // pre -> dp[i-1][j-1], dp[j-1] -> dp[i][j-1]
                    dp[j] = min({pre, last, dp[j-1]}) + 1;
                }
                sides = max(dp[j], sides);
                pre = last;
            }
        }
        return sides * sides;
    }
};