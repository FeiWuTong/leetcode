/*
 * Approach: dp
 * Time complexity: O(n^2)   || 45.74% (8 ms)
 * Space complexity: O(n)  || 100.00% (8.4 MB)
 */
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        if (triangle.size() == 0) return 0;
        vector<int> dp(1, triangle[0][0]);
        int cur, last;
        for (int i = 1; i < triangle.size(); i++) {
            for (int j = 0; j <= i; j++) {
                if (j != i) cur = dp[j];
                if (j == 0) dp[j] += triangle[i][j];
                else if (j < i) dp[j] = min(last, dp[j]) + triangle[i][j];
                else dp.push_back(last + triangle[i][j]);
                last = cur;
            }
        }
        return *min_element(dp.begin(), dp.end());
    }
};