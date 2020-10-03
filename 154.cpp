/*
 * Approach: Binary Search
 * Time complexity: O(n)   || 57.77% (8 ms)
 * Space complexity: O(1)  || 6.25% (12.3 MB)
 */
class Solution {
public:
    int findMin(vector<int>& nums) {
        int l = 0, lmin = nums[0], r = nums.size() - 1;
        while (l < r && nums[l] == nums[l+1]) l++;
        if (++l >= r) return min(lmin, nums[r]);;
        if (nums[l] < lmin) return nums[l];
        while (l < r) {
            int m = (l + r) >> 1;
            if (nums[m] > lmin) l = m + 1;
            else r = m;
        }
        return min(lmin, nums[r]);
    }
};
/*
 * Approach: Binary Search
 * Time complexity: O(n)   || 30.14% (12 ms)
 * Space complexity: O(1)  || 6.25% (12.3 MB)
 */
class Solution {
public:
    int findMin(vector<int>& nums) {
        int l = 0, r = nums.size() - 1;
        while (l < r) {
            int m = (l + r) >> 1;
            if (nums[m] > nums[r]) l = m + 1;
            else if (nums[m] == nums[r]) r--;
            else r = m;
        }
        return nums[l];
    }
};