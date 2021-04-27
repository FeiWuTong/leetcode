/*
 * Approach: refer to #84, and top-bottom DP
 * Time complexity: O(n^2)   || 62.26%
 * Space complexity: O(n)  || 100.00%
 * Note: scan and update the height row by row, each row can take as #84
 */
class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.size() == 0) return 0;
        int len = matrix[0].size();
        vector<int> h(len + 1, 0);
        h[len] = -1;
        int area = 0, top;

        for (int i = 0; i < matrix.size(); i++) {
            stack<int> s;
            for (int j = 0; j < len; j++) {
                h[j] = matrix[i][j] == '1' ? h[j] + 1 : 0;
            }
            for (int j = 0; j <= len; ) {
                if (s.empty() || h[j] >= h[s.top()]) s.push(j++);
                else {
                    top = s.top();
                    s.pop();
                    area = max(area, h[top] * (s.empty() ? j : j - 1 - s.top()));
                }
            }
        }
        return area;
    }
};
/*
 * Approach: full DP (brilliant)
 * Time complexity: O(n^2)   || 81.09%
 * Space complexity: O(n)  || 100.00%
 */
class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.size() == 0) return 0;
        int len = matrix[0].size();
        vector<int> h(len, 0);
        vector<int> left(len, 0);
        vector<int> right(len, len);
        int area = 0;

        for (int i = 0; i < matrix.size(); i++) {
            int row_left = 0, row_right = len;
            for (int j = 0; j < len; j++) {
                h[j] = matrix[i][j] == '1' ? h[j] + 1 : 0;
            }
            for (int j = 0; j < len; j++) {
                if (matrix[i][j] == '1') left[j] = max(left[j], row_left);
                else left[j] = 0, row_left = j + 1;
            }
            for (int j = len - 1; j >= 0; j--) {
                if (matrix[i][j] == '1') right[j] = min(right[j], row_right);
                else right[j] = len, row_right = j;
            }
            for (int j = 0; j < len; j++) area = max(area, h[j] * (right[j] - left[j]));
        }
        return area;
    }
};