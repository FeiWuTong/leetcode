/*
 * Approach: table
 * Time complexity: O(n)   || 92.60% (8 ms)
 * Space complexity: O(n)  || 100.00% (7 MB)
 */
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        char table[256] = {0};
        unordered_set<char> check;
        for (int i = 0; i < s.size(); i++) {
            if (table[s[i]]) {
                if (table[s[i]] != t[i]) return false;
            }
            else {
                if (check.count(t[i])) return false;
                table[s[i]] = t[i];
                check.insert(t[i]);
            }
        }
        return true;
    }
};