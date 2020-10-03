class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int res = 0, i, j;
        unordered_map<char, int> m;
        for (i = 0, j = 0; j < s.length(); j++) {
            if (m.find(s[j]) != m.end()) {
                if (i < m[s[j]]) {
                    res = j - i > res ? j - i : res;
                    i = m[s[j]];
                }
            }
            m[s[j]] = j + 1;
        }
        res = j - i > res ? j - i : res;
        return res;
    }
};