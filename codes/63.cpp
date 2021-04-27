/*
 * Approach: DP
 * Time complexity: O(m*n)   || 68.85%
 * Space complexity: O(m*n)  || 100.00%
 * Note: same as #62, but need to replace `int` with `long` / `unsigned int` type
 */
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n = obstacleGrid[0].size(), m = obstacleGrid.size();
        vector<vector<long>> dp(m, vector<long>(n, 1));
        for (int i = 0, obs = 0; i < n; i++) {
            if (!obs && obstacleGrid[0][i] == 1) {
                obs = 1;
                dp[0][i] = 0;
            }
            else if (obs) dp[0][i] = 0;
        }
        for (int i = 0, obs = 0; i < m; i++) {
            if (!obs && obstacleGrid[i][0] == 1) {
                obs = 1;
                dp[i][0] = 0;
            }
            else if (obs) dp[i][0] = 0;
        }
        for (int i = 1; i < n; i++) {
            for (int j = 1; j < m; j++) {
                if (obstacleGrid[j][i] == 1) dp[j][i] = 0;
                else dp[j][i] = dp[j-1][i] + dp[j][i-1];
            }
        }
        return dp[m-1][n-1];
    }
};