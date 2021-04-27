/*
 * Approach: stack (concise and brilliant)
 * Time complexity: O(n)   || 50.76%
 * Space complexity: O(n)  || 100.00%
 * Note: think every bar as a "smallest" base, then for every bar have a "biggest" area
 * Note: but there would be O(n^2) time complexity to find left and right index by trivial method
 * Note: take some skill can reduce to O(n), i.e., how to find left index and right index effectively
 */
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        heights.push_back(0); // sentinel
        int len = heights.size(), area = 0, top;
        stack<int> s;
        for (int i = 0; i < len; ) {
            if (s.empty() || heights[i] >= heights[s.top()]) s.push(i++);
            else {
                top = s.top();
                s.pop();
                area = max(area, heights[top] * (s.empty() ? i : i - 1 - s.top()));
            }
        }
        return area;
    }
};
/*
 * Approach: jump to find left and right index (DP)
 * Time complexity: O(n)   || 89.60%
 * Space complexity: O(n)  || 100.00%
 */
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int len = heights.size();
        if (len == 0) return 0;
        vector<int> left(len, -1);
        vector<int> right(len, len);
        int p;
        // left index search for every bar
        for (int i = 1; i < len; i++) {
            p = i - 1;
            while (p >= 0 && heights[i] <= heights[p]) p = left[p];
            left[i] = p;
        }
        // right index search for every bar
        for (int i = len - 2; i >= 0; i--) {
            p = i + 1;
            while (p < len && heights[i] <= heights[p]) p = right[p];
            right[i] = p;
        }
        int area = 0;
        for (int i = 0; i < len; i++) area = max(area, heights[i] * (right[i] - left[i] - 1));
        return area;
    }
};