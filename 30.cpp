/*
 * Approach: Two-Map windows two pass
 * Time complexity: O(N*wl) || 96.42%
 * Space complexity: O(wn)  || 97.78%
 */
class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> ans;
        int n = s.size(), wn = words.size();
        if (n == 0 || wn == 0) return ans;
        unordered_map<string, int> dict;
        for (int i = 0; i < wn; i++) dict[words[i]]++;
        int wl = words[0].size();
        for (int i = 0; i < wl; i++) {
            int left = i, cnt = 0;
            unordered_map<string, int> seen;
            for (int j = i; j <= n - wl; j += wl) {
                string sub_str = s.substr(j, wl);
                if (dict.count(sub_str)) {
                    seen[sub_str]++;
                    if (seen[sub_str] <= dict[sub_str]) cnt++;
                    else {
                        while (seen[sub_str] > dict[sub_str]) {
                            string sub_str1 = s.substr(left, wl);
                            seen[sub_str1]--;
                            if (seen[sub_str1] < dict[sub_str1]) cnt--;
                            left += wl;
                        }
                    }
                    if (cnt == wn) {
                        ans.push_back(left);
                        seen[s.substr(left, wl)]--;
                        cnt--;
                        left += wl;
                    }
                }
                else {
                    seen.clear();
                    cnt = 0;
                    left = j + wl;
                }
            }
        }
        return ans;
    }
};