/*
 * Approach: No
 * Time complexity: O(n)   || 57.12% (4 ms)
 * Space complexity: O(1)  || 100.00% (5.9 MB)
 */
class Solution {
public:
    int titleToNumber(string s) {
        int ret = 0;
        for (char c : s) {
            ret *= 26;
            ret += c - 'A' + 1;
        }
        return ret;
    }
};