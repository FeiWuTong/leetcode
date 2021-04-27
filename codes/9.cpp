/*
 * Approach: Revert half of the number
 * Time complexity: O(log10(x))  || 95.60%
 * Space complexity: O(1) || 99.67%
 * Note: it can reduce time and space, as well as avoid overflow.
 */
class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0 || (x % 10 == 0 && x != 0)) {
            return false;
        }
        int rev = 0;
        while (x > rev) {
            rev = rev * 10 + x % 10;
            x /= 10;
        }
        return x == rev || x == rev / 10;
    }
};