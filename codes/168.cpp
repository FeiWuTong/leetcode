/*
 * Approach: No
 * Time complexity: O(n)   || 100.00% (0 ms)
 * Space complexity: O(n)  || 100.00% (6.1 MB)
 */
class Solution {
public:
    string convertToTitle(int n) {
        string ret;
        while (n-- > 0) {
            ret.insert(0, 1, 'A' + n % 26);
            n /= 26;
        }
        return ret;
    }
};