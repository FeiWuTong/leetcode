/*
 * Approach: Binary Search
 * Time complexity: O(log(n))   || 25.24% (8 ms)
 * Space complexity: O(1)  || 6.67% (10.4 MB)
 */
class Solution {
public:
    int findMin(vector<int>& nums) {
        int l = 0, lmin = nums[0], r = nums.size() - 1;
        while (l < r) {
            int m = (l + r) >> 1;
            if (nums[m] >= lmin) l = m + 1;
            else r = m;
        }
        return min(lmin, nums[r]);
    }
};