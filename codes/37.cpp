/*
 * Approach: "Reactive network update propagation" and "Backtracking"
 * Time complexity: -      || 100.00%
 * Space complexity: -     || 21.92%
 * Note: also we can only use backtracking
 */
class Solution {
    struct cell {
        // value 1..9, 0 if unset
        uint8_t value;
        // amount of possible values (unconstrained)
        uint8_t numPossibilities;
        // bitset[v] = 1 then value can't be v
        bitset<10> constraints;
        cell() : value(0), numPossibilities(9), constraints() {};
    };
    array<array<cell, 9>, 9> cells;

    // also propagates constraints to other cells and deduces new values
    bool set(int i, int j, int v) {
        cell &c = cells[i][j];
        if (c.value == v) return true;
        if (c.constraints[v]) return false;
        c.constraints = bitset<10>(0x3FE);
        c.constraints.reset(v);
        c.numPossibilities = 1;
        c.value = v;
        
        // propagates constraints
        for (int k = 0; k < 9; k++) {
            // row
            if (i != k && !updateConstraints(k, j, v)) return false;
            // column
            if (j != k && !updateConstraints(i, k, v)) return false;
            // 3x3 grid
            int ix = i / 3 * 3 + k / 3;
            int jx = j / 3 * 3 + k % 3;
            if (i != ix && j != jx && !updateConstraints(ix, jx, v)) return false;
        }
        return true;
    }

    // once there's one possibility left, the function recurses back into set()
    bool updateConstraints(int i, int j, int excludedValue) {
        cell &c = cells[i][j];
        if (c.constraints[excludedValue]) return true;
        if (c.value == excludedValue) return false;
        c.constraints.set(excludedValue);
        if (--c.numPossibilities > 1) return true;
        for (int v = 1; v <= 9; v++) {
            if (!c.constraints[v]) return set(i, j, v);
        }
        assert(false);
    }

    // backtracking state - list of empty cells
    vector<pair<int, int>> bt;

    // find values for empty cells
    bool findValuesForEmptyCells() {
        bt.clear();
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (!cells[i][j].value)  bt.push_back(make_pair(i, j));
            }
        }
        // making backtracking efficient by pre-sorting empty cells by numPossibilities (smaller is better)
        sort(bt.begin(), bt.end(), [this](const pair<int, int>&a, pair<int, int>&b) {
            return cells[a.first][a.second].numPossibilities < cells[b.first][b.second].numPossibilities;
        });
        return backtrack(0);
    }

    // find value for all empty cells with index >= k
    bool backtrack(int k) {
        if (k >= bt.size()) return true;
        int i = bt[k].first;
        int j = bt[k].second;

        if (cells[i][j].value) return backtrack(k+1);
        auto constraints = cells[i][j].constraints;

        array<array<cell, 9>, 9> snapshot(cells);
        for (int v = 1; v <= 9; v++) {
            if (!constraints[v]) {
                if (set(i, j, v)) {
                    if (backtrack(k+1)) return true;
                }
                // restoring from snapshot,
				// note: computationally this is cheaper
				// than alternative implementation with undoing the changes
                cells = snapshot;
            }
        }
        return false;
    }

public:
    void solveSudoku(vector<vector<char>>& board) {
        cells = array<array<cell, 9>, 9>();
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] != '.' && !set(i, j, board[i][j] - '0')) return;
            }
        }
        if (!findValuesForEmptyCells()) return;

        for(int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (cells[i][j].value) board[i][j] = cells[i][j].value + '0';
            }
        }
    }
};

/*
 * Time complexity: -      || 77.16%
 * Space complexity: -     || 40.88%
 */
class Solution {
private:
    bool solveSudoku(vector<vector<char>>& board, int i, int j) {
        if (i == 9) return true;
        if (j == 9) return solveSudoku(board, i+1, 0);
        if (board[i][j] != '.') return solveSudoku(board, i, j+1);

        for (char c = '1'; c <= '9'; c++) {
            if (check(board, i, j, c)) {
                board[i][j] = c;
                if (solveSudoku(board, i, j+1)) return true;
                board[i][j] = '.';
            }
        }
        return false;
    }
    bool check(vector<vector<char>>& board, int i, int j, char val) {
        // top-left corner of its 9-grid cell
        int row = i - i % 3, col = j - j % 3;
        for (int x = 0; x < 9; x++) {
            if (board[x][j] == val) return false;
        }
        for (int x = 0; x < 9; x++) {
            if (board[i][x] == val) return false;
        }
        for (int x = 0; x < 3; x++) {
            for (int y = 0; y < 3; y++) {
                if (board[row+x][col+y] == val) return false;
            }
        }
        return true;
    }
public:
    void solveSudoku(vector<vector<char>>& board) {
        if (!solveSudoku(board, 0, 0)) return;
    }
};