/*
 * Approach: DP
 * Time complexity: O(n^2)   || 55.30% (52 ms)
 * Space complexity: O(n^2)  || 100.00% (7.2 MB)
 * Note: dp2[i] is minimum of dp2[j-1] + 1 (j <= i), if s[j, i] is palindrome
 */
class Solution {
public:
    int minCut(string s) {
        int n = s.size();
        if (n == 0) return 0;
        // Palindrome dp table
        vector<vector<bool>> dp(n, vector<bool>(n, false));
        vector<int> dp2(n, 0);
        for (int i = 0; i < n; i++) {
            // at most i cut
            int minCut = i;
            for (int j = 0; j <= i; j++) {
                if (s[j] == s[i] && (j + 1 >= i - 1 || dp[j + 1][i - 1])) {
                    dp[j][i] = true;
                    minCut = j == 0 ? 0 : min(minCut, dp2[j - 1] + 1);
                }
            }
            dp2[i] = minCut;
        }
        return dp2[n - 1];
    }
};
/*
 * Approach: DP (no palindrome dp table) (principle same as above)
 * Time complexity: O(n)   || 98.71% (8 ms)
 * Space complexity: O(n)  || 100.00% (6.4 MB)
 * Note: extend from middle to two-side (so no need for dp table)
 */
class Solution {
public:
    int minCut(string s) {
        int n = s.size();
        if (n == 0) return 0;
        vector<int> dp(n + 1, 0);
        for (int i = 0; i <= n; i++) dp[i] = i - 1;
        for (int i = 0; i < n; i++) {
            // dp[i] is in the middle (odd)
            for (int j = 0; j <= i && i + j < n && s[i-j] == s[i+j]; j++) {
                dp[i+j+1] = min(dp[i+j+1], dp[i-j] + 1);
            }
            // dp[i] and dp[i+1] is in the middle (even)
            for (int j = 0; j <= i && i + 1 + j < n && s[i-j] == s[i+1+j]; j++) {
                dp[i+j+2] = min(dp[i+j+2], dp[i-j] + 1);
            }
        }
        return dp[n];
    }
};