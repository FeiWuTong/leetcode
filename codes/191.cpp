/*
 * Approach: bit-manipulation (trick)
 * Time complexity: O(1)   || 100.00% (0 ms)
 * Space complexity: O(1)  || 100.00% (5.9 MB)
 * Note: every time AND operation flips 1-bit (i.e. least-significant bit-1)
 */
class Solution {
public:
    int hammingWeight(uint32_t n) {
        int ret = 0;
        while (n != 0) {
            ret++;
            n &= (n - 1);
        }
        return ret;
    }
};