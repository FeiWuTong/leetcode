/*
 * Approach: Two-Pointers (same as 15)
 * Time complexity: O(N^2)  || 100.00%
 * Space complexity: O(1)   || 99.72%
 * Note: Repeated num is necessary and cannot be ignored.
 */
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int ans, i = 0, last = nums.size() - 1;
        if (last < 2) {
            return 0;
        }
        else {
            ans = nums[0] + nums[1] + nums[2];
        }
        while (i < last) {
            int l = i + 1, r = last;
            while (l < r) {
                int sum = nums[i] + nums[l] + nums[r];
                if (abs(sum-target) < abs(ans - target)) ans = sum;
                if (sum < target) l++;
                else if (sum > target) r--;
                else return ans;
            }
            i++;
        }
        return ans;
    }
};