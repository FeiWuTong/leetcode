/*
 * Approach: table
 * Time complexity: O(n)   || 85.11% (16 ms)
 * Space complexity: O(n)  || 99.85% (7 MB)
 */
class Solution {
public:
    string sortString(string s) {
        int cnt[26] = {0};
        int n = s.size();
        for (char c : s) cnt[c-'a']++;
        for (int i = 0; i < n;) {
            for (int j = 0; j < 26; j++) {
                if (cnt[j] > 0) {
                    cnt[j]--;
                    s[i++] = 'a' + j;
                }
            }
            for (int j = 25; j >= 0; j--) {
                if (cnt[j] > 0) {
                    cnt[j]--;
                    s[i++] = 'a' + j;
                }
            }
        }
        return s;
    }
};