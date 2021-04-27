/*
 * Approach: backtracking
 * Time complexity: O(C{k}{N})   || 95.46% (60 ms)
 * Space complexity: O(C{k}{N})   || 100.00% (9.5 MB)
 */
class Solution {
private:
    void backtracking(vector<vector<int>> &ret, vector<int> &temp, int start, int n, int k) {
        if (k == 0) {
            ret.push_back(temp);
            return;
        }
        for (int i = start; i <= n - k + 1; i++) {
            temp.push_back(i);
            backtracking(ret, temp, i + 1, n, k - 1);
            temp.pop_back();
        }
    }
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ret;
        vector<int> temp;
        backtracking(ret, temp, 1, n, k);
        return ret;
    }
};
/*
 * Approach: backtracking (no recursion)
 * Time complexity: O(C{k}{N})    || 69.86% (80 ms)
 * Space complexity: O(C{k}{N})   || 100.00% (9.2 MB)
 */
class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ret;
        vector<int> temp(k, 0);
        int i = 0; // i represents start point
        while (i >= 0) {
            temp[i]++;
            if (temp[i] > n) i--;
            else if (i == k - 1) ret.push_back(temp);
            else {
                i++;
                temp[i] = temp[i - 1];
            }
        }
        return ret;
    }
};