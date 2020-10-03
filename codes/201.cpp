/*
 * Approach: bit-manipulation
 * Time complexity: O(1)   || 96.89% (4 ms)
 * Space complexity: O(1)  || 100.00% (6.1 MB)
 * Note: keep track of the range (n-m)
 */
class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        int ret = 0;
        for (int bit = 0; bit < 32; bit++) {
            int cur = 1 << bit;
            if (cur > m) break;
            if (n - m >= cur) continue;
            if (!(m & cur)) continue;
            // Indeed is (cur << 1) - 1 - ... >= n - m
            if ((cur - (m & (((cur - 1) << 1) + 1))) >= n - m + 1 - cur) ret |= cur;
        }
        return ret;
    }
};
/*
 * Approach: bit-manipulation
 * Time complexity: O(1)   || 84.23% (8 ms)
 * Space complexity: O(1)  || 100.00% (5.9 MB)
 * Note: In a word, find the common prefix of m and n 's binary code
 * Note: while m != n, there exists at least 1 bit different, no matter higher or equal to the last-bit
 * Note: i.e. in [m, n] the current last-bit must exist 1 and 0, AND -> 0
 */
class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        int move = 0;
        while (m != 0 && m != n) {
            m >>= 1;
            n >>= 1;
            move++;
        }
        return m << move;
    }
};
/*
 * Approach: recursive (bit-manipulation)
 * Time complexity: O(1)   || 60.83% (12 ms)
 * Space complexity: O(1)  || 100.00% (6 MB)
 * Note: after understanding #2, we can overwrite it into recursive solution (1 line)
 */
class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        return (m != 0 && m != n) ? (rangeBitwiseAnd(m >> 1, n >> 1) << 1) : m;
    }
};