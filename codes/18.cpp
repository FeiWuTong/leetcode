/*
 * Approach: Two-Pointers (same as 15)
 * Time complexity: O(N^3)   || 49.01%
 * Space complexity: O(N^4)  || 100.00%
 * Note: annotation below is optimized with less time cost but more code.
 */
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ret;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n;) {
            int a = nums[i];
            for (int j = i + 1; j < n;) {
                int l = j + 1, r = n - 1, b = nums[j];
                while (l < r) {
                    int c = nums[l], d = nums[r], sum = a + b + c + d;
                    if (sum == target) ret.push_back({a, b, c, d});
                    if (sum <= target) while (l < r && nums[l] == c) l++;
                    if (sum >= target) while (l < r && nums[r] == d) r--;
                }
                while (j < n && nums[j] == b) j++;
            }
            while (i < n && nums[i] == a) i++;
        }
        return ret;
    }
};
/* Time 87.98%, Space 100.00%
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ret;
        int n = nums.size();
        if (n < 4) return ret;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n - 3; i++) {
            if (i > 0 && nums[i] == nums[i-1]) continue;
            if (nums[i] + nums[i+1] + nums[i+2] + nums[i+3] > target) break;
            if (nums[i] + nums[n-1] + nums[n-2] + nums[n-3] < target) continue;
            for (int j = i + 1; j < n - 2; j++) {
                if (j > i + 1 && nums[j] == nums[j-1]) continue;
                if (nums[i] + nums[j] + nums[j+1] + nums[j+2] > target) break;
                if (nums[i] + nums[j] + nums[n-1] + nums[n-2] < target) continue;
                int l = j + 1, r = n - 1;
                while (l < r) {
                    int sum = nums[i] + nums[j] + nums[l] + nums[r];
                    if (sum == target) ret.push_back({nums[i], nums[j], nums[l], nums[r]});
                    if (sum <= target) {
                        l++;
                        while (l < r && nums[l] == nums[l-1]) l++;
                    }
                    if (sum >= target) {
                        r--;
                        while (l < r && nums[r] == nums[r+1]) r--;
                    }
                }
            }
        }
        return ret;
    }
};
*/