/*
 * Approach: Expand Around Center
 * Time complexity: O(n^2) || 83.3%
 * Space complexity: O(1)  || 100.00%
 * Note: use function(even inline function) will cost extra space overhead.
 */
class Solution {
public:
    string longestPalindrome(string s) {
        if (s.length() < 2) {
            return s;
        }
        int maxlen = 0, tmpmax = 0, center = 0, l, r;
        for (int i = 0; i < s.length(); i++) {
            //tmpmax = max(expansion(s, i, i), expansion(s, i, i+1));
            l = i, r = i;
            while (l >= 0 && r < s.length() && s[l] == s[r]) {
                l--;
                r++;
            }
            tmpmax = r - l - 1;
            l = i, r = i + 1;
            while (l >= 0 && r < s.length() && s[l] == s[r]) {
                l--;
                r++;
            }
            tmpmax = tmpmax > r - l - 1 ? tmpmax : r - l - 1;
            maxlen = max(maxlen, tmpmax);
            if (tmpmax >= maxlen) {
                maxlen = tmpmax;
                center = i;
            }
        }
        return s.substr(center-(maxlen-1)/2, maxlen);
    }
    
    /*
    inline int expansion(string s, int l, int r) {
        while (l >= 0 && r < s.length() && s[l] == s[r]) {
            l--;
            r++;
        }
        return r - l - 1;
    }
    */
};