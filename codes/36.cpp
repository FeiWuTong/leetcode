/*
 * Approach: Record and Check
 * Time complexity: O(81 * 6)   || 99.44%
 * Space complexity: O(243)     || 98.82%
 * Note: Less space cost version below
 */
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        // 0 -> row, 1 -> col, 2 -> grid
        bool sudoku[3][9][9] = { false };
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] != '.') {
                    int num = board[i][j] - '0' - 1;
                    if (sudoku[0][i][num] || sudoku[1][j][num] || 
                        sudoku[2][i/3*3+j/3][num]) return false;
                    sudoku[0][i][num] = true;
                    sudoku[1][j][num] = true;
                    sudoku[2][i/3*3+j/3][num] = true;
                }
            }
        }
        return true;
    }
};
/* Time: 96.09%, Space: 100.00%
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        bool grid[3][9], row[9], col[9][9] = { false };
        for (int i = 0; i < 9; i++) {
            memset(row, false, sizeof(row));
            if (i % 3 == 0) memset(grid, false, sizeof(grid));
            for (int j = 0; j < 9; j++) {
                if (board[i][j] != '.') {
                    int num = board[i][j] - '0' - 1;
                    if (row[num] || col[j][num] || grid[j/3][num]) return false;
                    row[num] = true;
                    col[j][num] = true;
                    grid[j/3][num] = true;
                }
            }
        }
        return true;
    }
};
*/