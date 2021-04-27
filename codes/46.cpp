/*
 * Approach: Recursion (and swap)
 * Time complexity:  -    || 99.82%
 * Space complexity: -    || 48.60%
 * Note: each round fix one number
 */
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        recursive(res, nums, 0);
        return res;
    }
private:
    void recursive(vector<vector<int>> &res, vector<int>& nums, int p) {
        if (p >= nums.size()) res.push_back(nums);
        else {
            for (int i = p; i < nums.size(); i++) {
                swap(nums[p], nums[i]);
                recursive(res, nums, p+1);
                swap(nums[p], nums[i]);
            }
        }
    }
};
/*
 * Approach: Backtrack (DFS)
 * Time complexity:  -    || 99.82%
 * Space complexity: -    || 46.38%
 */
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
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
                if (f[i]) continue;
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
 * Approach: Insert and Fix (no recursion)
 * Time complexity:  -    || 99.82%
 * Space complexity: -    || 99.94%
 * Note: same as usual thought, fix first, then second and so on.
 */
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();
        int total = 1;
        while (n--) total *= n;
        n = nums.size();
        vector<vector<int>> res(total, nums);
        // loop is skip times
        // cur is current position
        // times is the amount of each group's items
        int loop = 1, cur = 0, times = total;
        while (cur < n) {
            times /= n - cur;
            int line = 0;
            for (int j = 0; j < loop; j++) {
                // skip first group default
                line += times;
                for (int pos = cur+1; pos < n; pos++) {
                    for (int i = 0; i < times; i++) {
                        swap(res[line][cur], res[line][pos]);
                        line++;
                    }
                }
            }
            loop *= n - cur;
            cur++;
        }
        return res;
    }
};