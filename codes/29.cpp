/*
 * Approach: self-plus, not bit manipulates
 * Time complexity: O(log2(x))  || 100.00%
 * Space complexity: O(1)       || 100.00%
 * Note: Garbage problem, pay attention to overflow
 * Note2: Bit manipulation has the same performance but less code
 */
class Solution {
public:
    int divide(int dividend, int divisor) {
        if (divisor == 0) return -1;
        else if (divisor == 1) return dividend;
        else if (divisor == -1) {
            if (dividend == INT_MIN) return INT_MAX;
            return dividend - dividend - dividend;
        }
        else if (divisor == INT_MIN) return dividend == INT_MIN;
        int res = 0, sign = 1, acc = 0, jump, base = 1;
        if (dividend > 0) {
            if (divisor < 0) {
                divisor = divisor - divisor - divisor;
                sign = 0;
            }
        }
        else if (dividend == 0) return 0;
        else {
            if (dividend == INT_MIN) {
                if (divisor < 0) dividend -= divisor;
                else dividend += divisor;
                res++;
            }
            dividend = dividend - dividend - dividend;
            if (divisor < 0) divisor = divisor - divisor - divisor;
            else sign = 0;
        }
        jump = divisor;
        while (acc <= dividend) {
            if (acc > INT_MAX - jump || acc + jump > dividend) {
                jump = divisor;
                base = 1;
            }
            res += base;
            if (acc > INT_MAX - jump) break;
            else acc += jump;
            if (jump > INT_MAX - jump) {
                jump = divisor;
                base = 1;
            }
            else {
                jump += jump;
                base += base;
            }
        }
        res--;
        res = sign ? res : res - res - res;
        return res;
    }
};

/* Bit manipulation
class Solution {
public:
    int divide(int dividend, int divisor) {
        if (dividend == INT_MIN && divisor == -1) return INT_MAX;
        long dvd = labs(dividend), dvs = labs(divisor), res = 0;
        int sign = dividend > 0 ^ divisor > 0 ? -1 : 1;
        while (dvd >= dvs) {
            long tmp = dvs, m = 1;
            while (tmp << 1 <= dvd) {
                tmp <<= 1;
                m <<= 1;
            }
            dvd -= tmp;
            res += m;
        }
        return sign > 0 ? res : res - res - res;
    }
};
*/