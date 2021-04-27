/*
 * Approach: Manacher
 * Time complexity: O(n)  || 98.79%
 * Space complexity: O(n) || 88.85%
 */
class Solution {
public:
    string longestPalindrome(string s) {
        int len = s.length();
        if (len < 2) {
            return s;
        }
        
        // initialize
        len = len * 2 + 1;
        int maxlen = 0;
        int maxcenter = 0;
        // #a#b#a# as example
        vector<int> p(len, 1);
        int id = 1, mx = -1;
        
        // manacher
        for (int i = 1; i < len; i++) {
            if (i < mx) {
                p[i] = min(p[2*id-i], mx-i);
            }
            while ( (i + p[i] < len && i - p[i] >= 0) && \
                  ( (i + p[i]) % 2 == 0 or s[(i+p[i])/2] == s[(i-p[i])/2]) ) {
                p[i]++;
            }
            if (mx < i + p[i]) {
                id = i;
                mx = i + p[i];
            }
            if (maxlen < p[i]) {
                maxlen = p[i] - 1;
                maxcenter = i;
            }
        }
        return s.substr((maxcenter-maxlen)/2, maxlen);
    }
};