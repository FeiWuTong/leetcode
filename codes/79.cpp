/*
 * Approach: backtracking (simplest dfs)
 * Time complexity: -   || 68.28% (36 ms / 328 ms)
 * Space complexity: -  || 100.00% (8.3 MB / 186.5 MB)
 * Note: reference parameter is necessary for `word`, for time / space complexity improving 
 */
class Solution {
private:
    bool backtracking(vector<vector<char>>& board, vector<vector<bool>>& mask, string &word, int w_i, int x, int y) {
        if (w_i == word.size()) return true;
        if (x < 0 || x >= board.size() || y < 0 || y >= board[0].size()) return false;
        if (!mask[x][y]) return false;
        if (board[x][y] != word[w_i]) return false;
        mask[x][y] = false;
        if (backtracking(board, mask, word, w_i + 1, x-1, y) || 
            backtracking(board, mask, word, w_i + 1, x+1, y) ||
            backtracking(board, mask, word, w_i + 1, x, y-1) ||
            backtracking(board, mask, word, w_i + 1, x, y+1)) {
                return true;
            }
        mask[x][y] = true;
        return false;
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        vector<vector<bool>> mask(board.size(), vector<bool>(board[0].size(), true));
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                if (backtracking(board, mask, word, 0, i, j)) return true;
            }
        }
        return false;
    }
};
/*
 * Approach: optimize one
 * Time complexity: -   || 87.79%
 * Space complexity: -  || 100.00%
 */
class Solution {
private:
    bool backtracking(vector<vector<char>>& board, string &word, int w_i, int x, int y) {
        if (x < 0 || x >= board.size() || y < 0 || y >= board[0].size()) return false;
        if (board[x][y] != word[w_i]) return false;
        if (w_i == word.size() - 1) return true;
        
        board[x][y] += 128;
        if (backtracking(board, word, w_i + 1, x-1, y) || 
            backtracking(board, word, w_i + 1, x+1, y) ||
            backtracking(board, word, w_i + 1, x, y-1) ||
            backtracking(board, word, w_i + 1, x, y+1)) {
                return true;
            }
        board[x][y] -= 128;
        return false;
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                if (backtracking(board, word, 0, i, j)) return true;
            }
        }
        return false;
    }
};