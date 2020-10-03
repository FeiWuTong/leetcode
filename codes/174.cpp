/*
 * Approach: DP (reverse direction)
 * Time complexity: O(nm)   || 26.01% (16 ms)
 * Space complexity: O(nm)  || 100.00% (8.9 MB)
 * Note: hp[x][y] represents min hp needed at position (x, y)
 * Note: cannot navigate from top-left to bottom-right, because we cannot foresee the future demons (negative) to estimate needed health
 * Note: -5 -15 50  || -100 (for example which path should we choose when 2 * 3)
 * Note:  0  10  0  || -35  (which path should we choose when 2 * 4)
 */
class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int m = dungeon.size(), n = dungeon[0].size();
        vector<vector<int> > hp(m + 1, vector<int>(n + 1, INT_MAX));
        hp[m][n-1] = hp[m-1][n] = 1;
        for (int i = m - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                hp[i][j] = min(hp[i+1][j], hp[i][j+1]) - dungeon[i][j];
                if (hp[i][j] <= 0) hp[i][j] = 1;
            }
        }
        return hp[0][0];
    }
};
/*
 * Approach: DP (1D)
 * Time complexity: O(nm)   || 51.94% (12 ms)
 * Space complexity: O(n)  || 100.00% (9.1 MB)
 * Note: loop i is out-layer loop, therefore we just need to store dp for loop j
 */
class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int m = dungeon.size(), n = dungeon[0].size();
        vector<int> hp(n + 1, INT_MAX);
        hp[n-1] = 1;
        for (int i = m - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                hp[j] = min(hp[j], hp[j+1]) - dungeon[i][j];
                if (hp[j] <= 0) hp[j] = 1;
            }
        }
        return hp[0];
    }
};