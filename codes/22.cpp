/*
 * Approach: Stack
 * Time complexity: O(4^n/sqrt(n))   || 100.00%
 * Space complexity: O(4^n/n/sqrt(n))    || 99.35%
 * Note: Backtracking / recursion are the same performance but worse than stack(space cost is n times).
 * Note: Indeed space complexity is C(2n,n)/(n+1).
 */
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        stack<helper> s;
        s.push({"", n, 0});
        while (!s.empty()) {
            helper h = s.top();
            s.pop();
            if(h.leftpairs == 0 && h.remaining == 0) {
                result.push_back(h.s);
                continue;
            }
            if (h.remaining > 0) {
                s.push({h.s + ")", h.leftpairs, h.remaining-1});
            }
            if (h.leftpairs > 0) {
                s.push({h.s + "(", h.leftpairs-1, h.remaining+1});
            }
        }
        return result;
    }
private:
    struct helper {
        string s;
        int leftpairs;
        int remaining;
    };
};
/* Backtracking -- time: 97.96%, space: 61.02%
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        backtrack(res, "", 0, 0, n);
        return res;
    }
    void backtrack(vector<string>& res, string cur, int l, int r, int n) {
        if (cur.size() == n * 2) {
            res.push_back(cur);
            return;
        }
        if (l < n) backtrack(res, cur+"(", l+1, r, n);
        if (r < l) backtrack(res, cur+")", l, r+1, n);
    }
};
*/
/* Recursion -- time: 29.65%, space: 69.34%
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        if (n == 0) {
            res.push_back("");
        }
        else {
            for (int i = n-1; i >= 0; i--) {
                for (string l: generateParenthesis(i)) {
                    for (string r: generateParenthesis(n-i-1)) {
                        res.push_back("("+l+")"+r);
                    }
                }
            }
        }
        return res;
    }
};
*/