/*
 * Approach: recursion
 * Time complexity: -   || 99.46%
 * Space complexity: -  || 100.00%
 */
class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ret;
        ret.push_back(vector<int>());
        sort(nums.begin(), nums.end());
        int s, j;
        for (int i = 0; i < nums.size(); i++) {
            if (i > 0 && nums[i] == nums[i-1]) j = s;
            else j = 0;
            for (s = ret.size(); j < s; j++) {
                vector<int> temp = ret[j];
                temp.push_back(nums[i]);
                ret.push_back(temp);
            }
        }
        return ret;
    }
};
/*
 * Approach: Backtracking
 * Time complexity: -   || 99.46%
 * Space complexity: -  || 100.00%
 */
class Solution {
private:
    void backtrack(vector<vector<int>>& ret, vector<int>& nums, vector<int>& temp, int start) {
        ret.push_back(temp);
        for (int i = start; i < nums.size(); i++) {
            if (i == start || nums[i] != nums[i - 1]) {
                temp.push_back(nums[i]);
                backtrack(ret, nums, temp, i + 1);
                temp.pop_back();
            }
        }
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ret;
        vector<int> temp;
        backtrack(ret, nums, temp, 0);
        return ret;
    }
};