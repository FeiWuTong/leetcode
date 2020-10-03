/*
 * Approach: DP
 * Time complexity: O(m*n)   || 100.00%
 * Space complexity: O(m*n)  || 100.00%
 * Note: Right -> m-1, Down -> n-1
 */
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, 1));
        for (int i = 1; i < n; i++) {
            for (int j = 1; j < m; j++) {
                dp[j][i] = dp[j-1][i] + dp[j][i-1];
            }
        }
        return dp[m-1][n-1];
    }
};