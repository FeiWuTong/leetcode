/*
 * Approach: Backtracking
 * Time complexity:  -       || 98.87%
 * Space complexity: -       || 86.43%
 * Note: flag "stop" is necessary to reduce time cost (from 268ms -> 4ms)
 * Note: elegant solution below
 */
class Solution {
private:
    bool stop = 0;
    bool ismatch(string& s, string& p, int i, int j) {
        while (i < s.length() && j < p.length()) {
            if (s[i] == p[j] || p[j] == '?') {
                i++;
                j++;
            }
            else {
                if (p[j] == '*') {
                    while(j < p.length() && p[j] == '*') j++;
                    if (j == p.length()) return true;
                    else {
                        while (i < s.length()) {
                            if (ismatch(s, p, i, j)) return true;
                            if (stop) return false;
                            i++;
                        }
                    }
                }
                else return false;
            }
        }
        if (i == s.length()) {
            stop = 1;
            if (j == p.length()) return true;
            else {
                while (j < p.length() && p[j] == '*') j++;
                if (j != p.length()) return false;
                return true;
            }
        }
        return false;
    }
public:
    bool isMatch(string s, string p) {
        if (ismatch(s, p, 0, 0)) return true;
        return false;
    }
};
/*
 * Approach: Greedy
 * Time complexity:  -       || 98.87%
 * Space complexity: O(1)    || 85.23%
 * Note: use pointer for p's star and pointer for s's snapshot to finish backtracking
 */
class Solution {
public:
    bool isMatch(string s, string p) {
        int star = -1;
        int si = 0, pi = 0;
        int ss = si;
        while (si < s.length()) {
            if (pi < p.length() && (p[pi] == '?' || p[pi] == s[si])) {
                si++;
                pi++;
            }
            else if (pi < p.length() && p[pi] == '*') {
                star = pi++;
                ss = si;
            }
            // Backtracking
            else if (star != -1) {
                pi = star + 1;
                si = ++ss;
            }
            else return false;
        }
        while (pi < p.length() && p[pi] == '*') pi++;
        return pi == p.length();
    }
};
/*
 * Approach: DP
 * Time complexity:  -       || 53.74% (68ms)
 * Space complexity: O(n)    || 84.35%
 * Note: use pre, i.e., cur[0] to make DP 2 dimension to 1 dimension
 */
class Solution {
public:
    bool isMatch(string s, string p) {
        // bad trick for acceptance
        int i = s.length()-1, j = p.length()-1;
        while (i >= 0 && j >= 0 && p[j] == '?') { i--; j--; }
        if (i >= 0 && j >= 0 && p[j] != '*' && s[i] != p[j]) return false;

        // cur[i] represent whether s[i] is matched
        vector<bool> cur(s.length()+1, false);
        cur[0] = true; // used to judge whether is all star before
        for (j = 1; j <= p.length(); j++) {
            // pre represent dp[i-1][j-1]
            bool pre = cur[0];
            cur[0] = cur[0] && p[j-1] == '*';
            for (i = 1; i <= s.length(); i++) {
                bool tmp = cur[i];
                if (p[j-1] != '*')
                    cur[i] = pre && (s[i-1] == p[j-1] || p[j-1] == '?');
                else cur[i] = cur[i-1] || cur[i];
                pre = tmp;
            }
        }
        return cur[s.length()];
    }
};