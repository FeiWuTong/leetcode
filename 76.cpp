/*
 * Approach: two pointers 2 pass (use queue) hash table
 * Time complexity: O(s.len)   || 25.43% (56 ms)
 * Space complexity: O(s.len)  || 100.00% (8.5 MB)
 */
class Solution {
public:
    string minWindow(string s, string t) {
        int l = 0, r = 0;
        pair<int, int> pos(0, s.size());
        map<char, int> c_t;
        int total = 0;
        for (int i = 0; i < t.size(); i++) {
            if (c_t.count(t[i])) c_t[t[i]]++;
            else {
                c_t[t[i]] = 1;
                total++;
            }
        }
        assert(total != 0);
        queue<int> jump;
        while (r < s.size()) {
            if (c_t.count(s[r])) {
                --c_t[s[r]] == 0 ? --total : 1;
                jump.push(r);
            }
            if (total == 0) {
                do {
                    l = jump.front();
                    jump.pop();
                } while (c_t[s[l]]++ < 0);
                if (pos.second - pos.first + 1 > r - l) {
                    pos.first = l, pos.second = r;
                }
                total++;
            }
            r++;
        }
        if (pos.second == s.size()) return "";
        else return string(s, pos.first, pos.second - pos.first + 1);
    }
};
/*
 * Approach: two pointers 2 pass (no queue) hash table
 * Time complexity: O(s.len)   || 21.31% (68 ms)
 * Space complexity: O(1)  || 100.00% (7.6 MB)
 */
class Solution {
public:
    string minWindow(string s, string t) {
        int l = 0, r = 0;
        pair<int, int> pos(0, s.size());
        map<char, int> c_t;
        int total = 0;
        for (int i = 0; i < t.size(); i++) {
            if (c_t.count(t[i])) c_t[t[i]]++;
            else {
                c_t[t[i]] = 1;
                total++;
            }
        }
        assert(total != 0);
        while (r < s.size()) {
            if (c_t.count(s[r])) --c_t[s[r]] == 0 ? --total : 1;
            if (total == 0) {
                while (l < s.size()) {
                    if (c_t.count(s[l]) && ++c_t[s[l]] > 0) break;
                    l++;
                }
                if (pos.second - pos.first + 1 > r - l) {
                    pos.first = l, pos.second = r;
                }
                total++;
                l++;
            }
            r++;
        }
        if (pos.second == s.size()) return "";
        else return string(s, pos.first, pos.second - pos.first + 1);
    }
};
/*
 * Approach: two pointers 2 pass (no queue) vector table
 * Time complexity: O(s.len)   || 96.02% (8 ms)
 * Space complexity: O(1)  || 100.00% (7.7 MB)
 * Note: same as before, but <map> is much slower
 */
class Solution {
public:
    string minWindow(string s, string t) {
        vector<int> c_t(128, 0);
        for (int i = 0; i < t.size(); i++) c_t[t[i]]++;
        int total = 0, l = -1, len = s.size() + 1, pos = 0;
        for (int i = 0; i < s.size(); i++) {
            if (c_t[s[i]]-- > 0) total++;
            while (total == t.size()) {
                if (++c_t[s[pos]] > 0) {
                    if (len > i - pos + 1) {
                        len = i - pos + 1;
                        l = pos;
                    }
                    total--;
                }
                pos++;
            }
        }
        return l == -1 ? "" : s.substr(l, len);
    }
};