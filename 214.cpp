/*
 * Approach: KMP
 * Time complexity: O(n)   || 75.71% (8 ms)
 * Space complexity: O(n)  || 54.93% (7.9 MB)
 * Note: Indeed it is the problem that "find the longest palindrome substring start from index 0"
 * Note: then we get the tail (out of substr) and reverse it, insert the reverse one to the start
 * Note: we can use `manacher` or `KMP` to find that substr, with O(n) time cost
 * Note: `KMP` is used to find the longest prefix, so we need to make a trick: reverse str and concatenate them, which makes palindrome possible
 */
class Solution {
public:
    string shortestPalindrome(string s) {
        string s_rev = s;
        reverse(s_rev.begin(), s_rev.end());
        string ss = s + "#" + s_rev;
        vector<int> len(ss.size(), 0);
        // KMP
        for (int i = 1, j; i < ss.size(); i++) {
            j = len[i-1];
            while (j > 0 && ss[i] != ss[j]) j = len[j-1];
            len[i] = (j += ss[i] == ss[j]);
        }
        if (len[ss.size() - 1] == s.size()) return s;
        return s_rev.substr(0, s_rev.size() - len[ss.size()-1]) + s;
    }
};
/*
 * Approach: iterative with pointer
 * Time complexity: O(n^2)   || 75.71% (8 ms)
 * Space complexity: O(1)  || 98.49% (7.1 MB)
 * Note: due to O(n^2), will cause TLE, if skip all repetitive characters can optimize it
 */
class Solution {
public:
    string shortestPalindrome(string s) {
        int n = s.size(), longest = 0;
        for (int next = 0, i, j; next < (n + 1) >> 1;) {
            // new round
            i = j = next;
            // skip repetitive part s[next...j], which is palindrome
            while (j < n - 1 && s[j+1] == s[j]) j++;
            // prepare for next round
            next = j + 1;
            // expand repetitive part's palindrome
            while (j < n - 1 && i > 0 && s[j+1] == s[i-1]) i--, j++;
            // is prefix, update longest
            if (i == 0) longest = j - i + 1;
        }
        if (longest == n) return s;
        string s_rev = s.substr(longest);
        reverse(s_rev.begin(), s_rev.end());
        return s_rev + s;
    }
};