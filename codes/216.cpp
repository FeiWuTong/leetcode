/*
 * Approach: backtracking
 * Time complexity: O(n)   || 100.00% (0 ms)
 * Space complexity: O(n)  || 70.88% (6.4 MB)
 */
class Solution {
private:
    vector<vector<int>> ret;
    vector<int> cur;
    /* 4 ms / 6.5 MB
    void backtracking(int k, int n) {
        if (!k && !n) ret.push_back(cur);
        else if (k) {
            for (int i = cur.size() ? cur.back() + 1 : 1; i <= n && i <= 9; i++) {
                cur.push_back(i);
                backtracking(k - 1, n - i);
                cur.pop_back();
            }
        }
    }
    */
    void backtracking(int k, int n) {
        if (!k) ret.push_back(cur);
        else {
            if (k == 1) {
                if (n > 9) return;
                else {
                    cur.push_back(n);
                    ret.push_back(cur);
                    cur.pop_back();
                }
            } else {
                for (int i = cur.size() ? cur.back() + 1 : 1; i * 2 < n && i <= 9; i++) {
                    cur.push_back(i);
                    backtracking(k - 1, n - i);
                    cur.pop_back();
                }
            }
        }
    }
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        backtracking(k, n);
        return ret;
    }
};