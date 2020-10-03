/*
 * Approach: Recursive (DFS)
 * Time complexity: O(n)   || 37.41% (804 ms)
 * Space complexity: O(n)  || 31.18% (105.4 MB)
 * Note: keep track of the expression's value so far
 */
class Solution {
private:
    // cur: {string} expression generated so far.
    // pos: {int}    current visiting position of num.
    // cv:  {long}   cumulative value so far.
    // pv:  {long}   previous operand value.
    void dfs(vector<string>& res, string& num, int target, string cur, int pos, long cv, long pv) {
        if (pos == num.size() && cv == target) {
            res.push_back(cur);
        } else {
            // i represents the substr length
            for (int i = 1; i <= num.size() - pos; i++) {
                string t = num.substr(pos, i);
                // multi 0s
                if (i > 1 && t[0] == '0') break;
                long v = stol(t);
                if (pos == 0) {
                    dfs(res, num, target, t, i, v, v);
                } else {
                    dfs(res, num, target, cur + "+" + t, pos + i, cv + v, v);
                    dfs(res, num, target, cur + "-" + t, pos + i, cv - v, -v);
                    dfs(res, num, target, cur + "*" + t, pos + i, cv - pv + pv * v, pv * v);
                }
            }
        }
    }
public:
    vector<string> addOperators(string num, int target) {
        vector<string> res;
        dfs(res, num, target, "", 0, 0, 0);
        return res;
    }
};