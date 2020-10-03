/*
 * Approach: Two pass windows (Bi-search)
 * Time complexity: O(2n)  || 33.02%
 * Space complexity: O(1)  || 100.00%
 * Note: Better one below this solution
 */
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int i = nums.size() - 2;
        while (i >= 0 && nums[i+1] <= nums[i]) i--;
        if (i >= 0) {
            int r = nums.size() - 1, l = i + 1, m;
            if (nums[r] > nums[i]) m = r, l = r;
            while (r > l) {
                m = (l + r) / 2;
                if (nums[m] <= nums[i]) r = m - 1;
                else l = m + 1;
            }
            if (nums[l] <= nums[i]) l--;
            swap(nums[i], nums[l]);
        }
        int r = nums.size();
        while (++i < --r) swap(nums[i], nums[r]);
    }
};
/* Time: 100.00%, space: 100.00%
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int i = nums.size() - 1, k = i;
        while (i > 0 && nums[i-1] >= nums[i]) i--;
        for (int j = i; j < k; j++, k--) swap(nums[j], nums[k]);
        if (i > 0) {
            k = i--;
            while (nums[k] <= nums[i]) k++;
            swap(nums[k], nums[i]);
        }
    }
};
*/