/*
 * Approach: DP
 * Time complexity: O(m*n)   || 85.81%
 * Space complexity: O(m*n)  || 100.00%
 * Note: Right -> m-1, Down -> n-1
 */
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        for (int i = 1; i < grid[0].size(); i++) grid[0][i] += grid[0][i-1];
        for (int i = 1; i < grid.size(); i++) grid[i][0] += grid[i-1][0];
        for (int i = 1; i < grid[0].size(); i++) {
            for (int j = 1; j < grid.size(); j++) {
                grid[j][i] += min(grid[j-1][i], grid[j][i-1]);
            }
        }
        return grid[grid.size()-1][grid[0].size()-1];
    }
};