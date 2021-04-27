/*
 * Approach: stack
 * Time complexity: O(n)   || 43.56% (24 ms)
 * Space complexity: O(n)  || 5.26% (12.2 MB)
 * Note: Reverse Polish Notation
 */
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for (string token : tokens) {
            if ((token[0] >= '0' && token[0] <= '9') || (token[0] == '-' && token.size() != 1)) {
                st.push(stoi(token));
            } else {
                int x = st.top();
                st.pop();
                int y = st.top();
                st.pop();
                if (token[0] == '+') st.push(y+x);
                else if (token[0] == '-') st.push(y-x);
                else if (token[0] == '*') st.push(y*x);
                else st.push(y/x);
            }
        }
        return st.top();
    }
};
/*
 * Approach: map lambda expression
 * Time complexity: O(n)   || 10.81% (36 ms)
 * Space complexity: O(n)  || 5.26% (12.2 MB)
 */
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        unordered_map<int, function<int (int, int)>> m = {
            { '+', [] (int x, int y) { return x + y; } },
            { '-', [] (int x, int y) { return x - y; } },
            { '*', [] (int x, int y) { return x * y; } },
            { '/', [] (int x, int y) { return x / y; } },
        };
        stack<int> st;
        for (string& token : tokens) {
            if (token.size() != 1 || !m.count(token[0])) {
                st.push(stoi(token));
            } else {
                int x = st.top();
                st.pop();
                int y = st.top();
                st.pop();
                st.push(m[token[0]](y, x));
            }
        }
        return st.top();
    }
};