/*
 * Approach: No
 * Time complexity: O(n)   || 12.23% (32 ms)
 * Space complexity: O(n)  || 29.73% (64.6 MB)
 */
class Solution {
public:
    string reverseWords(string s) {
        int n = s.size();
        if (n == 0) return s;
        string ret = "";
        int last = s[0] == ' ';
        for (int i = 1; i < n; i++) {
            if (s[i] == ' ') {
                if (s[i-1] != ' ') ret = " " + s.substr(last, i - last) + ret;
                last = i + 1;
            }
        }
        if (s[n-1] != ' ') ret = s.substr(last, n - last) + ret;
        return ret[0] == ' ' ? ret.substr(1) : ret;
    }
};
/*
 * Approach: in place
 * Time complexity: O(n)   || 29.60% (20 ms)
 * Space complexity: O(1)  || 100.00% (7.1 MB)
 * Note: reverse the string and word
 */
class Solution {
public:
    string reverseWords(string s) {
        reverse(s.begin(), s.end());
        int start = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] != ' ') {
                if (start != 0) s[start++] = ' ';
                int j = i;
                while (j < s.size() && s[j] != ' ') s[start++] = s[j++];
                reverse(s.begin() + start - (j - i), s.begin() + start);
                i = j;
            }
        }
        s.resize(start);
        return s;
    }
};