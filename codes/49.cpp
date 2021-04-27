/*
 * Approach: Map to record
 * Time complexity:  O(n*m*logm)    || 94.33%
 * Space complexity: O(n*m)         || 49.27%
 */
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        unordered_map<string, vector<string>> m;
        for (string s : strs) {
            string t = s;
            sort(t.begin(), t.end());
            m[t].push_back(s);
            /*
            int a[26] = {0};
            for (char c : s) a[c-'a']++;
            string key = "";
            for (int c = 0; c < 26; c++) key += string(a[c], c+'a');
            m[key].push_back(s);
            */
        }
        for (auto s : m) {
            res.push_back(s.second);
        }
        return res;
    }
};