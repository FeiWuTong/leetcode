/*
 * Approach: DFS
 * Time complexity: O(n^2)   || 33.98% (28 ms)
 * Space complexity: O(n^2)  || 100.00% (9.7 MB)
 */
class Solution {
private:
    int d[4][2] = { {1, 0}, {-1, 0}, {0, 1}, {0, -1} };
    int m, n;
    void recursive(vector<vector<char>>& grid, int x, int y) {
        if (x < 0 || x >= m || y < 0 || y >= n || grid[x][y] != '1') return;
        grid[x][y] = '#';
        for (int i = 0; i < 4; i++) recursive(grid, x + d[i][0], y + d[i][1]);
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        m = grid.size();
        if (m == 0) return 0;
        n = grid[0].size();
        int ret = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '1') {
                    ret++;
                    recursive(grid, i, j);
                }
            }
        }
        return ret;
    }
};
/*
 * Approach: Union Find
 * Time complexity: O(n^2)   || 33.98% (28 ms)
 * Space complexity: O(n^2)  || 100.00% (10.3 MB)
 * Note: UF in `Algorithm.cpp`
 */
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        if (m == 0) return 0;
        int n = grid[0].size();
        UF uf = UF(m * n + 1);
        int dummy = m * n;
        // traverse and Union connected '1'
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '1') {
                    int cur = i * n + j;
                    if (i + 1 < m && grid[i+1][j] == '1') uf.Union(cur, cur + n);
                    if (j + 1 < n && grid[i][j+1] == '1') uf.Union(cur, cur + 1);
                }
            }
        }
        // traverse and count islands
        int cnt = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '1') {
                    int cur = i * n + j;
                    // find a new island
                    if (!uf.connected(cur, dummy)) {
                        cnt++;
                        uf.Union(cur, dummy);
                    }
                }
            }
        }
        return cnt;
    }
};