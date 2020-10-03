/*
 * Approach: in-place
 * Time complexity: O(mn)   || 89.27% / 16.46%
 * Space complexity: O(1)  || 100.00%
 * Note: O(mn) straight forward solution means save zeroes positions
 * Note: O(m+n) means save row and col state, total m+n
 * Note: O(1) means save every row and col state in original matrix
 */
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        // extra space for matrix[0][0]
        int c0 = 1, rows = matrix.size(), cols = matrix[0].size();
        for (int i = 0; i < rows; i++) {
            if (matrix[i][0] == 0) c0 = 0;
            for (int j = 1; j < cols; j++) {
                if (matrix[i][j] == 0) matrix[i][0] = matrix[0][j] = 0;
            }
        }
        for (int i = 1; i < rows; i++) {
            if (matrix[i][0] == 0) {
                for (int j = 1; j < cols; j++) matrix[i][j] = 0;
            }
            if (c0 == 0) matrix[i][0] = 0;
        }
        for (int j = 1; j < cols; j++) {
            if (matrix[0][j] == 0) {
                for (int i = 1; i < rows; i++) matrix[i][j] = 0;
            }
            if (matrix[0][0] == 0) matrix[0][j] = 0;
        }
        if (c0 == 0) matrix[0][0] = 0;
        /*
        // from bottom to top, from right to left, finally 0th row / col
        for (int i = rows - 1; i >= 0; i--) {
            for (int j = cols - 1; j >= 1; j--) {
                if (matrix[i][0] == 0 || matrix[0][j] == 0) matrix[i][j] = 0;
            }
            if (c0 == 0) matrix[i][0] = 0;
        }
        */
    }
};