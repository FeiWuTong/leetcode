/*
 * Approach: Recursion (fix one by one)
 * Time complexity:  -    || 99.34%
 * Space complexity: -    || 17.92%
 * Note: need to check whether has exchanged the same value before
 */
class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> res;
        recursive(res, nums, 0);
        return res;
    }
private:
    void recursive(vector<vector<int>> &res, vector<int>& nums, int p) {
        if (p >= nums.size()) res.push_back(nums);
        else {
            for (int i = p; i < nums.size(); i++) {
                if (i == p) {
                    recursive(res, nums, p+1);
                }
                else {
                    int j = i-1;
                    while (j >= p && nums[j] != nums[i]) j--;
                    if (j == p-1) {
                        swap(nums[p], nums[i]);
                        recursive(res, nums, p+1);
                        swap(nums[p], nums[i]);
                    }
                }
            }
        }
    }
};
/*
 * Approach: Backtracking
 * Time complexity:  -    || 39.64%
 * Space complexity: -    || 72.72%
 * Note: same as last(#46) problem solution
 */
class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        vector<int> tmp;
        vector<bool> f(nums.size(), false);
        backtrack(res, nums, tmp, f);
        return res;
    }
private:
    void backtrack(vector<vector<int>> &res, vector<int>& nums, vector<int>& tmp, vector<bool>& f) {
        if (tmp.size() == nums.size()) res.push_back(tmp);
        else {
            for (int i = 0; i < nums.size(); i++) {
                if (f[i] || i > 0 && nums[i] == nums[i-1] && !f[i-1]) continue;
                tmp.push_back(nums[i]);
                f[i] = true;
                backtrack(res, nums, tmp, f);
                tmp.pop_back();
                f[i] = false;
            }
        }
    }
};
/*
 * Approach: Recursion2 (also fix one by one)
 * Time complexity:  -    || 99.34%
 * Space complexity: -    || 17.92%
 * Note: no need to check before and re-swap, but need to sort first
 * Note: remain unfixed numbers will also keep in sorted order
 */
class Solution {
public:
    void recursion(vector<int> num, int p, vector<vector<int>> &res) {
        if (p >= num.size()-1) {
            res.push_back(num);
            return;
        }
        for (int i = p; i < num.size(); i++) {
            if (i != p && num[i] == num[p]) continue;
            swap(num[i], num[p]);
            recursion(num, p+1, res);
        }
    }
    vector<vector<int>> permuteUnique(vector<int> &num) {
        sort(num.begin(), num.end());
        vector<vector<int>> res;
        recursion(num, 0, res);
        return res;
    }
};
/*
 * Approach: - (No recursion, elegant)
 * Time complexity:  -    || 99.34%
 * Space complexity: -    || 84.14%
 * Note: Unfix from tail to head (reverse is elegant, keep unfixed number in order)
 * Note: Similar to human's solution
 */
class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
         vector<vector<int>> res;
         sort(nums.begin(), nums.end());
         do {
            res.push_back(nums);
        } while (nextPermutation(nums));
        return res;
    }
    bool nextPermutation(vector<int>& nums) {
        if (nums.size() < 2)
            return false;
        for (int i = nums.size() - 2; i >= 0; i--) {
            if (nums[i] < nums[i + 1]) {
                for (int j = nums.size() - 1; j > i; j--) {
                    if (nums[j] > nums[i]) {
                        swap(nums[i], nums[j]);
                        reverse(nums.begin() + i + 1, nums.end());
                        return true;
                    }
                }
            }
        }
        return false;
    }
};