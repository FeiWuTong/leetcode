/*
 * Approach: No
 * Time complexity: O(n^2)   || 100.00% (0 ms)
 * Space complexity: O(n^2)  || 100.00% (6.3 MB)
 */
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ret;
        for (int i = 0; i < numRows; i++) {
            vector<int> cur(i + 1, 1);
            for (int j = 1; j < i; j++) { cur[j] = ret[i-1][j-1] + ret[i-1][j]; }
            ret.push_back(cur);
        }
        return ret;
    }
};