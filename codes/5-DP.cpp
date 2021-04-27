/*
 * Approach: Dynamic Programming (common)
 * Time complexity: O(n^2)  || 33.52%
 * Space complexity: O(n^2) || 65.07%
 * Note1: Save only upper part of diagonal can reduce half of the space.
 * Note2: Hash or Set can improve space complexity further even to O(n).
 */
class Solution {
public:
    string longestPalindrome(string s) {
        int len = s.length();
        if (len < 2) {
            return s;
        }
        bool dp[len][len] = { false };
        int maxlen = 0, start = 0, i, j;
        // initialize
        for (j = 0; j + 1 < len; j++) {
            dp[j][j] = true;
            dp[j][j+1] = (s[j] == s[j+1]);
        }
        dp[len-1][len-1] = true;
        // i is the interval
        for (i = 2; i < len; i++) {
            for (int j = 0; j + i < len; j++) {
                dp[j][j+i] = (dp[j+1][j+i-1] && s[j] == s[j+i]);
            }
        }
        for (i = len - 1; i >= 0; i--) {
            for (j = len - 1; j - i >= 0; j--) {
                if (dp[j-i][j] && i + 1 > maxlen) {
                    maxlen = i + 1;
                    start = j - i;
                    return s.substr(start, maxlen);
                }
            }
        }
        return "";
    }
};

/*
 * Approach: Dynamic Programming (hash)
 * Time complexity: O(n^2)  || 8.20%
 * Space complexity: O(2n)~O(n) || 54.71%
 * Note1: Save only upper part of diagonal can reduce half of the space.
 * Note2: Hash or Set can improve space complexity further even to O(n).
 * Note3: Hash may take more space for keeping efficiency when test case is small.
 */
class Solution {
public:
    struct eo {
        int a[2];
    };

    string longestPalindrome(string s) {
        int len = s.length();
        if (len < 2) {
            return s;
        }
        unordered_map<int, eo> m;
        int maxlen = 1, start, i, j;
        for (i = 0; i < len; i++) {
            m[i].a[0] = i;
            if (s[i] == s[i+1]) {
                m[i].a[1] = i + 1;
                maxlen = 2;
                start = i;
                continue;
            }
            if (maxlen != 2) {
                start = i;
            }
        }
        // i is the interval, a[0] represent even, a[1] represent odd
        for (i = 2; i < len; i++) {
            for (j = 1; j + i - 1 < len; j++) {
                if (m[j].a[i%2] - j == i - 2 && s[j-1] == s[j+i-1]) {
                    m[j-1].a[i%2] = j + i - 1;
                    maxlen = i + 1;
                    start = j - 1;
                }
            }
        }
        return s.substr(start, maxlen);
    }
};