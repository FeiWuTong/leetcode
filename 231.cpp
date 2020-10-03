/*
 * Approach: Recursive (check every bit)
 * Time complexity: O(lgn)   || 48.59% (4 ms)
 * Space complexity: O(lgn)  || 30.84% (6.1 MB)
 * Note: bitset or iterative is also ok
 */
class Solution {
public:
    bool isPowerOfTwo(int n) {
        return n > 0 && (n == 1 || (!(n & 1) && isPowerOfTwo(n >> 1)));
    }
};
/*
 * Approach: utilize n-1
 * Time complexity: O(1)   || 100.00% (0 ms)
 * Space complexity: O(1)  || 92.83% (5.8 MB)
 * Note: power of 2 means only 1 bit is set, and n & (n - 1) == 0
 */
class Solution {
public:
    bool isPowerOfTwo(int n) {
        return n > 0 && !(n & (n - 1));
    }
};
/*
 * Approach: math
 * Time complexity: O(1)   || 5.21% (8 ms)
 * Space complexity: O(1)  || 7.43% (6.2 MB)
 * Note: the max possible power of 2 is 2^30, which means 2^30 % n == 0 when n is power of 2
 */
class Solution {
public:
    bool isPowerOfTwo(int n) {
        return n > 0 && (1073741824 % n == 0);
    }
};