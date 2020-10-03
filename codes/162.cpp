/*
 * Approach: Binary Search
 * Time complexity: O(log(n))   || 44.21% (8 ms)
 * Space complexity: O(1)  || 29.55% (8.8 MB)
 */
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int l = 0, r = nums.size() - 1;
        while (l < r) {
            int m = (l + r) >> 1;
            // rising
            if (nums[m] < nums[m+1]) l = m + 1;
            // falling
            else r = m;
        }
        return l;
    }
};