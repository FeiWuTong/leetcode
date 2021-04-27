/*
 * Approach: KMP
 * Time complexity: O(n+p) || 92.13%
 * Space complexity: O(p)  || 99.22%
 */
class Solution {
public:
    int strStr(string haystack, string needle) {
        if (needle.size() == 0) return 0;
        // generate next[];
        int next[needle.size()];
        next[0] = -1;
        for (int j = 0, k = -1; j < needle.size() - 1;) {
            if (k == -1 || needle[j] == needle[k]) next[++j] = ++k;
            else k = next[k];
        }
        // strstr();
        int i = 0, j = 0;
        for (; i < haystack.size() && j < needle.size();) {
            if (haystack[i] == needle[j]) {
                i++;
                j++;
            }
            else if (j == 0) i++;
            else j = next[j];
        }
        return j == needle.size() ? i - j : -1;
    }
};

/* KMP but not concise, and slower version
int next[needle.size()];
next[0] = -1;
int i, j;
for (i = 1; i < needle.size(); i++) {
    for (j = next[i-1];; j = next[j]) {
        if (j == -1) {
            next[i] = 0;
            break;
        }
        else if (needle[j] == needle[i-1]) {
            next[i] = j + 1;
            break;
        }
    }
}
*/