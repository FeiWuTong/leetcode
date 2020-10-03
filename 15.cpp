/*
 * Approach: Two-Pointers
 * Time complexity: O(NlogN+N^2) ~ O(N^2)  || 72.50%
 * Space complexity: O(N^3) || 99.40%
 * Note1: Dynamic Programming may work with time O(2N^2) ~ O(N^2).
 * Note2: Brute Force make time O(N^3).
 * Note3: int(num.size()) is necessary for nums.size() is unsigned int.
 */
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ret;
        sort(nums.begin(), nums.end());
        int i = 0, l, r, s;
        while (i < int(nums.size()) - 1) {
            l = i + 1, r = nums.size() - 1;
            while (l < r) {
                s = nums[i] + nums[l] + nums[r];
                if (s == 0) {
                    ret.push_back({nums[i], nums[l], nums[r]});
                }
                if (s <= 0) {
                    l++;
                    while (l < r && nums[l] == nums[l-1]) l++;
                }
                if (s >= 0) {
                    r--;
                    while (l < r && nums[r] == nums[r+1]) r--;
                }
            }
            i++;
            while (i < nums.size() - 1 && nums[i] == nums[i-1]) i++; 
        }
        return ret;
    }
};