/*
 * Approach: math
 * Time complexity: O(logn)   || 100.00% (0 ms)
 * Space complexity: O(1)  || 74.45% (5.9 MB)
 * Note: go through the digit position one at a time, find out "1" count at each position
 * Note: e.g. 1231 -> total 123+1 -- '1'(1, 1/10), 13*10+0 -- '1' (10-19, 10/100),
 * Note:              2 * 100 + 0 (100-199, 100/1000), 0 + 232(1000-1999, 1000/10000)
 */
class Solution {
public:
    int countDigitOne(int n) {
        int ones = 0;
        for (long long m = 1; m <= n; m *= 10) {
            ones += (n / m + 8) / 10 * m + (n / m % 10 == 1) * (n % m + 1);
        }
        return ones;
    }
};