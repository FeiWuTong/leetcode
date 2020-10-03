/*
 * Approach: Recursive (DFS)
 * Time complexity: O(n^2)   || 98.84% (24 ms)
 * Space complexity: O(n^2)  || 100.00% (10.3 MB)
 */
class Solution {
private:
    int direct[4][2] = { {1, 0}, {-1, 0}, {0, 1}, {0, -1} };
    int m, n;
    void recursive(vector<vector<char>>& board, int x, int y) {
        if (x < 0 || x == m || y < 0 || y == n || board[x][y] != 'O') return;
        board[x][y] = '#';
        for (int i = 0; i < 4; i++) {
            recursive(board, x + direct[i][0], y + direct[i][1]);
        }
    }
    void replace(vector<vector<char>>& board) {
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == 'O') board[i][j] = 'X';
                else if (board[i][j] == '#') board[i][j] = 'O';
            }
        }
    }
public:
    void solve(vector<vector<char>>& board) {
        m = board.size();
        if (m == 0) return;
        n = board[0].size();
        // border DFS
        for (int i = 0; i < n; i++) {
            recursive(board, 0, i);
            recursive(board, m - 1, i);
        }
        for (int i = 0; i < m; i++) {
            recursive(board, i, 0);
            recursive(board, i, n - 1);
        }
        // recorve '#' and replace 'O'
        replace(board);
    }
};
/*
 * Approach: Union Find
 * Time complexity: O(n^2)   || 67.87% (36 ms)
 * Space complexity: O(n^2)  || 100.00% (10.5 MB)
 * Note: UF class is defined in `Algorithm.cpp`
 */
class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int m = board.size();
        if (m == 0) return;
        int n = board[0].size();
        int dummy = m * n;
        UF uf = UF(dummy + 1);
        // border union to dummy
        for (int i = 0; i < n; i++) {
            if (board[0][i] == 'O') uf.Union(i, dummy);
            if (board[m - 1][i] == 'O') uf.Union((m - 1) * n + i, dummy);
        }
        for (int i = 1; i < m - 1; i++) {
            if (board[i][0] == 'O') uf.Union(i * n, dummy);
            if (board[i][n - 1] == 'O') uf.Union(i * n + n - 1, dummy);
        }
        // inside 'O' union
        int direct[][2] = { {1, 0}, {-1, 0}, {0, 1}, {0, -1} };
        for (int i = 1; i < m - 1; i++) {
            for (int j = 1; j < n - 1; j++) {
                if (board[i][j] == 'O') {
                    for (int k = 0; k < 4; k++) {
                        int x = i + direct[k][0];
                        int y = j + direct[k][1];
                        if (board[x][y] == 'O') uf.Union(x * n + y, i * n + j);
                    }
                }
            }
        }
        // replace 'O' that not union to dummy
        for (int i = 1; i < m - 1; i++) {
            for (int j = 1; j < n - 1; j++) {
                if (!uf.connected(dummy, i * n + j)) board[i][j] = 'X';
            }
        }
    }
};