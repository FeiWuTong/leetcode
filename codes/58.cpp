/*
 * Approach: NO
 * Time complexity: O(n)   || 100.00%
 * Space complexity: O(1)  || 100.00%
 */
class Solution {
public:
    int lengthOfLastWord(string s) {
        int i = s.size() - 1, count = 0;
        for (; i > 0; i--) {
            if (s[i] != ' ') break;
        }
        for (; i >= 0; i--, count++) {
            if (s[i] == ' ') return count;
        }
        return count;
    }
};