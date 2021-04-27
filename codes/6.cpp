/*
 * Approach: Read by Row (look for pattern)
 * Time complexity: O(n)  || 94.23%
 * Space complexity: O(n) || 100.00%
 */
class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1) {
            return s;
        }
        int n = s.size(), k = 0;
        int jump = 2 * numRows - 2;
        char ans[n+1];
        for (int i = 0; i < numRows; i++) {
            for (int j = 0; j + i < n; j += jump) {
                ans[k++] = s[j+i];
                if (i != 0 && i != numRows - 1 && j + jump - i < n) {
                    ans[k++] = s[j+jump-i];
                }
            }
        }
        ans[k] = '\0';
        return ans;
    }
};