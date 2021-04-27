/*
 * Approach: table
 * Time complexity: O(n)   || 87.11% (16 ms)
 * Space complexity: O(n)  || 61.13% (7.3 MB)
 * Note: unicode use a[256]
 */
class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) return false;
        int a[26] = {0};
        for (char c : s) a[c-'a']++;
        for (char c : t) {
            if (--a[c-'a'] < 0) return false;
        }
        return true;
    }
};