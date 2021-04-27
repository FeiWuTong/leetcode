/*
 * Approach: Dynamic Programming
 * Time complexity: O(TP)  || 100.00%
 * Space complexity: O(TP) || 100.00%
 * Note: T, P represent the lengths of the text and the pattern respectively.
 */
class Solution {
public:
    bool isMatch(string s, string p) {
        bool dp[s.size()+1][p.size()+1], fi;
        for(int i = 0; i <= s.size(); i++) {
            for (int j = 0; j <= p.size(); j++) {
                dp[i][j] = false;
            }
        }
        dp[s.size()][p.size()] = true;
        for (int i = s.size(); i >= 0; i--) {
            for (int j = p.size() - 1; j >= 0; j--) {
                fi = i < s.size() && (p[j] == s[i] || p[j] == '.');
                if (j + 1 < p.size() && p[j+1] == '*') {
                    dp[i][j] = dp[i][j+2] || fi && dp[i+1][j];
                }
                else {
                    dp[i][j] = fi && dp[i+1][j+1];
                }
            }
        }
        return dp[0][0];
    }
};