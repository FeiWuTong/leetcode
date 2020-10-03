/*
 * Approach: no
 * Time complexity: O(n)   || 82.20% (20 ms)
 * Space complexity: O(n)  || 53.80% (15.9 MB)
 * Note: Please solve it without division and in O(n).
 */
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> ret(n, 1);
        // 1: left to right (****n....)
        for (int i = 1; i < n; i++) {
            ret[i] = ret[i-1] * nums[i-1];
        }
        // 2: right to left (....n****)
        int right = 1;
        for (int i = n - 1; i >= 0; i--) {
            ret[i] *= right;
            right *= nums[i];
        }
        return ret;
    }
};
// conflate 54.83% (24 ms), 65.86% (15.7 MB)
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size(), right = 1, left = 1;
        vector<int> ret(n, 1);
        for (int i = 0; i < n; i++) {
            ret[i] *= left;
            left *= nums[i];
            ret[n-1-i] *= right;
            right *= nums[n-1-i];
        }
        return ret;
    }
};