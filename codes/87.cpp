/*
 * Approach: DP and recursion
 * Time complexity: O(5^N)   || 8.51%-10.97% (272 - 236 ms)
 * Space complexity: -  || 9.52% (35.3 - 32.8 MB)
 * Note: can break loop advance
 */
class Solution {
private:
    unordered_map<string, bool> m;
public:
    bool isScramble(string s1, string s2) {
        int n = s1.size();
        if (n == 0) return true;
        else if(n == 1) return s1 == s2;
        else {
            if (m.count(s1 + s2)) return m[s1 + s2];
            if (s1 == s2) return m[s1 + s2] = true;
            else {
                for (int i = 1; i < n; i++) {
                    /*
                    if (isScramble(s1.substr(0, i), s2.substr(0, i)) && isScramble(s1.substr(i, n - i), s2.substr(i, n - i))) {
                        return m[s1 + s2] = true;
                    }
                    if (isScramble(s1.substr(0, i), s2.substr(n - i, i)) && isScramble(s1.substr(i, n - i), s2.substr(0, n - i))) {
                        return m[s1 + s2] = true;
                    }
                    */
                    if (isScramble(s1.substr(0, i), s2.substr(0, i))) {
                        if (isScramble(s1.substr(i, n - i), s2.substr(i, n - i))) return m[s1 + s2] = true;
                    }
                    if (isScramble(s1.substr(0, i), s2.substr(n - i, i))) {
                        if (isScramble(s1.substr(i, n - i), s2.substr(0, n - i))) return m[s1 + s2] = true;
                        return m[s1 + s2] = false; // break loop advance
                    }
                }
            }
        }
        return m[s1 + s2] = false;
    }
};
/*
 * Approach: bottom-up DP and no recursion
 * Time complexity: O(N^4)   || 80.02%   (8 ms)
 * Space complexity: O(N^3)  || 100.00% (6.3 MB)
 * Note: dp[len][i][j] represents whether s2[j..j+len-1] is a scramble of s1[i..i+len-1]
 */
class Solution {
public:
    bool isScramble(string s1, string s2) {
        int n = s1.size();
        bool dp[n+1][n][n];
        dp[0][0][0] = true;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                dp[1][i][j] = s1[i] == s2[j];
            }
        }
        for (int len = 2; len <= n; len++) {
            for (int i = 0; i <= n - len; i++) {
                for (int j = 0; j <= n - len; j++) {
                    dp[len][i][j] = false;
                    for (int k = 1; k < len && !dp[len][i][j]; k++) {
                        dp[len][i][j] = dp[len][i][j] || (dp[k][i][j] && dp[len - k][i + k][j + k]);
                        dp[len][i][j] = dp[len][i][j] || (dp[k][i][j + len - k] && dp[len - k][i + k][j]);
                    }
                }
            }
        }
        return dp[n][0][0];
    }
};