/*
 * Approach: Stack
 * Time complexity: O(n)   || 100.00%
 * Space complexity: O(n)  || 100.00%
 */
class Solution {
public:
    bool isValid(string s) {
        stack<char> p;
        for (auto l : s) {
            if (l == '(' || l == '[' || l == '{') p.push(l);
            else {
                if (p.empty()) return false;
                if (l == ')') {
                    if (p.top() == '(') p.pop();
                    else return false;
                }
                else if (l == ']') {
                    if (p.top() == '[') p.pop();
                    else return false;
                }
                else {
                    if (p.top() == '{') p.pop();
                    else return false;
                }
            }
        }
        return p.empty();
    }
};