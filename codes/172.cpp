/*
 * Approach: No
 * Time complexity: O(lgn) || 100.00% (0 ms)
 * Space complexity: O(1)  || 100.00% (5.9 MB)
 */
class Solution {
public:
    int trailingZeroes(int n) {
        int ret = 0;
        for (int i = 5; i <= n; i *= 5) {
            ret += n / i;
            if (i > INT_MAX / 5) break;
        }
        return ret;
    }
};