/*
 * Approach: Fibonacci-like (same as #118)
 * Time complexity: O(n)   || 100.00% (0 ms)
 * Space complexity: O(n)  || 100.00% (6.5 MB)
 */
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> last(1, 1), cur(2, 1);
        if (rowIndex == 0) return last;
        if (rowIndex == 1) return cur;
        for (int i = 2; i <= rowIndex; i++) {
            last = cur;
            cur = vector<int>(i + 1, 1);
            for (int j = 1; j < i; j++) cur[j] = last[j-1] + last[j];
        }
        return cur;
    }
};