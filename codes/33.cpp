/*
 * Approach: Bi-Search with min and max
 * Time complexity: O(log(n))   || 100.00%
 * Space complexity: O(1)       || 100.00%
 */
class Solution {
public:
    int search(vector<int>& nums, int target) {
        if (!nums.size()) return -1;
        int l = 0, r = nums.size() - 1, m;
        int min = nums[l], max = nums[r];
        if (target < min && target > max) return -1;
        while (l < r) {
            m = (l + r) / 2;
            // should be in left part
            if (target >= min) {
                if (nums[m] < min) r = m - 1;
                else if (nums[m] < target) l = m + 1;
                else if (nums[m] == target) return m;
                else if (nums[m] > target) r = m - 1;
            }
            // should be in right part
            else if (target <= max) {
                if (nums[m] > max) l = m + 1;
                else if (nums[m] < target) l = m + 1;
                else if (nums[m] == target) return m;
                else if (nums[m] > target) r = m - 1;
            }
        }
        return nums[l] == target ? l : -1;
    }
};