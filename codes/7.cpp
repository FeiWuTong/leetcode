/*
 * Approach: Pop and Push Digits / Check Overflow
 * Time complexity: O(log10(x))  || 100.00%
 * Space complexity: O(1) || 100.00%
 */
class Solution {
public:
    int reverse(int x) {
        int r = 0, p;
        while (x != 0) {
            p = x % 10;
            x /= 10;
            if (r > INT_MAX / 10 || (r == INT_MAX / 10 && p > 7)) {
                return 0;
            }
            else if (r < INT_MIN / 10 || (r == INT_MIN / 10 && p < -8)) {
                return 0;
            }
            r = r * 10 + p;
        }
        return r;
    }
};