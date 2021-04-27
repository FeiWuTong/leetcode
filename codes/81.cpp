/*
 * Approach: Bi-Search (modify #33)
 * Time complexity: O(log(n)~n)   || 98.02% ~ 6.31%
 * Space complexity: O(1)  || 100.00%
 * Note: should pay attention to duplicates case, i.e. when nums[m] == lmin == rmax
 * Note: lmin or rmax can be deleted, but use it can be more readable
 */
class Solution {
public:
    bool search(vector<int>& nums, int target) {
        if (nums.size() == 0) return false;
        int l = 0, r = nums.size() - 1, m;
        int lmin = nums[l], rmax = nums[r];
        if (target < lmin && target > rmax) return false;
        if (target == lmin) return true;
        if (lmin == rmax) {
            while (++l < nums.size() && nums[l] == lmin);
            while (--r > 0 && nums[r] == rmax);
        }
        if (r < 0) return false;
        if (target > lmin) {  // left part
            while (l < r) {
                m = (l + r) >> 1;
                if (nums[m] < lmin || nums[m] > target) r = m;
                else if (nums[m] == target) return true; // 12ms -> 4ms
                else l = m + 1;
            }
        }
        else {  // right part
            while (l < r) {
                m = (l + r) >> 1;
                if (nums[m] > rmax || nums[m] < target) l = m + 1;
                else if (nums[m] == target) return true; // 12ms -> 4ms
                else r = m;
            }
        }
        return nums[r] == target ? true : false;
    }
};
/* concise one T:43.22% */
// for nums[l] is the benchmark of left part and right part, when
// nums[m] == nums[l], we just go through it by increasing l
class Solution {
public:
    bool search(vector<int>& nums, int target) {
        if (nums.size() == 0) return false;
        int l = 0, r = nums.size() - 1, m;
        while (l < r) {
            m = (l + r) >> 1;
            if (nums[m] == target) return true;
            if (nums[m] > nums[l]) { // left part
                if (nums[l] <= target && nums[m] > target) r = m;
                else l = m + 1;
            }
            else if (nums[m] < nums[l]) { // right part
                if (nums[r] >= target && nums[m] < target) l = m + 1;
                else r = m;
            }
            else l++;
        }
        return nums[r] == target ? true : false;
    }
};