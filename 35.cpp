/*
 * Approach: Bi-Search
 * Time complexity: O(log(n))   || 98.59%
 * Space complexity: O(1)       || 97.84%
 */
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        if (!nums.size()) return 0;
        int l = 0, r = nums.size() - 1, m;
        while (l < r) {
            m = (l + r) / 2;
            if (nums[m] < target) l = m + 1;
            else if (nums[m] > target) r = m - 1;
            else return m;
        }
        return nums[l] >= target ? l : l + 1;
    }
};