/*
 * Approach: one pass sum
 * Time complexity: O(n)   || 99.25%
 * Space complexity: O(1)  || 99.75%
 * Note: divide and conquer approach below
 */
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum = 0, max = nums[0];
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            max = sum > max ? sum : max;
            sum = sum > 0 ? sum : 0;
        }
        return max;
    }
};
/*
 * Approach: divide and conquer
 * Time complexity: O(nlog(n))   || 99.25%
 * Space complexity: O(1)        || 98.90%
 */
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        return maxsubarray(nums, 0, nums.size()-1);
    }
    int maxsubarray(vector<int>& nums, int l, int r) {
        if (l == r) return nums[l];
        int m = (l + r) / 2, ml = nums[m], mr = nums[m+1];
        int lmax = maxsubarray(nums, l, m);
        int rmax = maxsubarray(nums, m+1, r);
        for (int i = m, sum = 0; i >= l; i--) {
            sum += nums[i];
            ml = sum > ml ? sum : ml;
        }
        for (int i = m + 1, sum = 0; i <= r; i++) {
            sum += nums[i];
            mr = sum > mr ? sum : mr;
        }
        lmax = rmax > lmax ? rmax : lmax;
        return lmax > ml + mr ? lmax : ml + mr;
    }
};