/*
 * Approach: Binary Search
 * Time complexity: average O(logn + logm)   || 23.23% (232 ms)
 * Space complexity: O(1)  || 39.75% (10.8 MB)
 * Note: worst O(min(m, n)(logm + logn))
 */
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        if (n == 0) return false;
        int m = matrix[0].size();
        if (m == 0) return false;
        n--, m--;
        if (matrix[n][m] < target) return false;
        if (matrix[n][m] == target) return true;
        int start = 0, l, mid;
        while (start <= n && start <= m) {
            l = start;
            // 1: check row boundary (n is the last one less than target)
            // O(logn)
            while (l <= n) {
                mid = (l + n) >> 1;
                if (matrix[mid][start] < target) l = mid + 1;
                else if (matrix[mid][start] == target) return true;
                else n = mid - 1;
            }
            // 2: check col boundary (m is the last one less than target)
            // O(logm)
            l = start;
            while (l <= m) {
                mid = (l + m) >> 1;
                if (matrix[start][mid] < target) l = mid + 1;
                else if (matrix[start][mid] == target) return true;
                else m = mid - 1;
            }
            // 3: next round
            start++;
        }
        return false;
    }
};
/*
 * Approach: No
 * Time complexity: O(m+n)   || 97.78% (84 ms)
 * Space complexity: O(1)  || 10.09% (10.9 MB)
 */
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        if (n == 0) return false;
        int m = matrix[0].size();
        for (int i = 0, j = m - 1; i < n && j >= 0;) {
            if (matrix[i][j] < target) i++;
            else if (matrix[i][j] > target) j--;
            else return true;
        }
        return false;
    }
};
/*
 * Approach: devide and conquer (recursive)
 * Time complexity: O(N^(1/log3(4)) )   || 17.16% (304 ms)
 * Space complexity: O(1)  || 82.24% (10.7 MB)
 * Note: find 'center' point and devide the whole matrix into 4 sub-matrix
 * Note: T(N) <= 3*T(N/4) + O(1), N = m*n
 */
class Solution {
private:
    int tt;
    bool recursive(vector<vector<int>>& m, int rs, int re, int cs, int ce) {
        if (rs > re || cs > ce || m[re][ce] < tt) return false;
        int rm = (rs + re) >> 1, cm = (cs + ce) >> 1;
        if (m[rm][cm] == tt) return true;
        if (m[rm][cm] > tt) {
            return recursive(m, rs, rm - 1, cs, cm - 1) ||
                   recursive(m, rm, re, cs, cm - 1)     ||
                   recursive(m, rs, rm - 1, cm, ce);
        }
        return recursive(m, rm + 1, re, cm + 1, ce) ||
               recursive(m, rm + 1, re, cs, cm)     ||
               recursive(m, rs, rm, cm + 1, ce);
    }
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        if (n == 0) return false;
        int m = matrix[0].size();
        tt = target;
        return recursive(matrix, 0, n - 1, 0, m - 1);
    }
};