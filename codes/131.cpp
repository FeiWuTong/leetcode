/*
 * Approach: Backtracking
 * Time complexity: O(n*2^n)   || 96.36% (12 ms)
 * Space complexity: -  || 100.00% (10 MB)
 */
class Solution {
private:
    vector<vector<string>> ret;
    vector<string> cur;
    bool isPalindrome(string& s, int l, int r) {
        if (l == r) return true;
        while (l < r) {
            if (s[l] != s[r]) return false;
            l++, r--;
        }
        return true;
    }
    void backtracking(string& s, int start) {
        if (start == s.size()) ret.push_back(cur);
        else {
            for (int i = start; i < s.size(); i++) {
                if (isPalindrome(s, start, i)) {
                    cur.push_back(s.substr(start, i - start + 1));
                    backtracking(s, i + 1);
                    cur.pop_back();
                }
            }
        }
    }
public:
    vector<vector<string>> partition(string s) {
        backtracking(s, 0);
        return ret;
    }
};
/*
 * Approach: Backtracking + DP (no need to check Palindrome)
 * Time complexity: O(2^n)   || 89.46% (16 ms)
 * Space complexity: -  || 100.00% (10.1 MB)
 * Note: backtracking just put Palindromes into ret
 */
class Solution {
private:
    vector<vector<string>> ret;
    vector<string> cur;
    void backtracking(string& s, int start, vector<vector<bool>>& dp) {
        if (start == s.size()) ret.push_back(cur);
        else {
            for (int i = start; i < s.size(); i++) {
                if (dp[start][i]) {
                    cur.push_back(s.substr(start, i - start + 1));
                    backtracking(s, i + 1, dp);
                    cur.pop_back();
                }
            }
        }
    }
public:
    vector<vector<string>> partition(string s) {
        vector<vector<bool>> dp(s.size(), vector<bool>(s.size(), false));
        for (int i = 0; i < s.size(); i++) {
            for (int j = 0; j <= i; j++) {
                if (s[j] == s[i] && (i - j <= 2 || dp[j+1][i-1])) dp[j][i] = true;
            }
        }
        backtracking(s, 0, dp);
        return ret;
    }
};