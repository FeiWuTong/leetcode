/*
 * Approach: DP (my solution)
 * Time complexity: O(n)  || 94.93%
 * Space complexity: O(n)  || 65.81%
 * Note: Stack with special solution can also solute with O(n)
 */
class Solution {
public:
    int longestValidParentheses(string s) {
        if (s.length() <= 1) return 0;
        int res = 0;
        vector<int> l(s.length(), 0);
        for (int i = 1; i < s.length(); i++) {
            if (s[i] == ')' && i - l[i-1] - 1 >= 0 && s[i-l[i-1]-1] == '(') {
                l[i] = l[i-1] + 2 + ((i - l[i-1] - 2 >= 0) ? l[i-l[i-1]-2] : 0);
                res = max(l[i], res);
            }
        }
        return res;
    }
};
/*
 * Approach: Stack (genius idea)
 * Time complexity: O(n)  || 46.00%
 * Space complexity: O(n)  || 67.42%
 * Note: stack not stores characters but indexes
 */
class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> st;
        int res = 0;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == ')') {
                if (!st.empty()) {
                    if (s[st.top()] == '(') st.pop();
                    else st.push(i);
                }
                else st.push(i);
            }
            else st.push(i);
        }
        if (st.empty()) res = s.length();
        else {
            int a = s.length(), b = 0;
            while (!st.empty()) {
                b = st.top();
                st.pop();
                res = max(res, a-b-1);
                a = b;
            }
            res = max(res, a);
        }
        return res;
    }
};