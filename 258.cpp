/*
 * Approach: Math
 * Time complexity: O(1)   || 100.00% (0 ms)
 * Space complexity: O(1)  || 81.65% (5.9 MB)
 * Note: Could you do it without any loop/recursion in O(1) runtime?
 * Note: wiki - digit root [https://en.wikipedia.org/wiki/Digital_root#Congruence_formula]
 * Note: find out its periodic regularity: 0-9 -> 0-9, 10-18 -> 1-9, 19-27 -> 1-9
 * Note: Indeed, dr(n) = 0 if n == 0, dr(n) = (b-1) if n != 0 and n % (b-1) == 0, dr(n) = n % (b-1) if n % (b-1) != 0
 * Note: i.e. first 0 to (base-1) against 0 to (base-1), then the remain num is in 1 to (base-1) period
 */
class Solution {
public:
    int addDigits(int num) {
        return 1 + (num - 1) % 9;
    }
};