/*
 * Approach: Stack (two pass) (my solution)
 * Time complexity:  O(n)    || 99.59%
 * Space complexity: O(n)    || 57.69%
 */
class Solution {
public:
    int trap(vector<int>& height) {
        stack<int> st;
        int res = 0, ground;
        st.push(0);
        for (int i = 1; i < height.size(); i++) {
            while (height[i] >= height[st.top()]) {
                ground = height[st.top()];
                st.pop();
                if (!st.empty()) {
                    res += (min(height[i], height[st.top()]) - ground) * (i - st.top() - 1);
                }
                else break;
            }
            st.push(i);
        }
        return res;
    }
};
/*
 * Approach: DP
 * Time complexity:  O(n)    || 99.59%
 * Space complexity: O(n)    || 74.20%
 */
class Solution {
public:
    int trap(vector<int>& height) {
        if (height.size() < 2) return 0;
        int res = 0;
        int n = height.size();
        vector<int> left_max(n), right_max(n);
        left_max[0] = height[0];
        for (int i = 1; i < n; i++) {
            left_max[i] = max(height[i], left_max[i-1]);
        }
        right_max[n-1] = height[n-1];
        for (int i = n-2; i >= 0; i--) {
            right_max[i] = max(height[i], right_max[i+1]);
        }
        for (int i = 1; i < n-1; i++) {
            res += min(left_max[i], right_max[i]) - height[i];
        }
        return res;
    }
};
/*
 * Approach: 2 pointers
 * Time complexity:  O(n)    || 99.59%
 * Space complexity: O(1)    || 63.85%
 */
class Solution {
public:
    int trap(vector<int>& height) {
        int res = 0;
        int l = 0, r = height.size() - 1;
        int l_max = 0, r_max = 0;
        while (l < r) {
            if (height[l] < height[r]) {
                height[l] >= l_max ? (l_max = height[l]) : res += l_max - height[l];
                l++;
            }
            else {
                height[r] >= r_max ? (r_max = height[r]) : res += r_max-height[r];
                r--;
            }
        }
        return res;
    }
};