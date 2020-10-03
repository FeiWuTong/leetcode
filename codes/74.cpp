/*
 * Approach: Binary Search
 * Time complexity: -   || 88.17%
 * Space complexity: -  || 100.00%
 * Note: treat m rows n cols 2D matrix as a m*n 1D matrix
 * Note: if m * n is too large, then search row first, then col
 */
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        if (m == 0) return false;
        int n = matrix[0].size();
        if (n == 0) return false;
        int l = 0, r = m * n - 1, mid;
        while (l < r) {
            mid = (l + r) >> 1;
            if (target > matrix[mid / n][mid % n]) l = mid + 1;
            else r = mid;
        }
        return matrix[r / n][r % n] == target;
    }
};