/*
 * Approach: Lexicographic (bitmask)
 * Time complexity: O(2^N)   || 97.57%
 * Space complexity: O(2^N)  || 100.00%
 */
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ret;
        int n = nums.size();
        for (int i = 0; i < pow(2, n); i++) {
            bitset<10> bitmask(i);
            ret.push_back(vector<int>());
            for (int j = 0; j < n; j++) {
                if (bitmask[j] == 1) ret.back().push_back(nums[j]);
            }
        }
        return ret;
    }
};
/*
 * Approach: recursion
 * Time complexity: O(2^N)   || 97.64%
 * Space complexity: O(2^N)  || 100.00%
 */
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ret;
        ret.push_back(vector<int>());
        for (int num : nums) {
            for (int i = 0, n = ret.size(); i < n; i++) {
                vector<int> temp = ret[i];
                temp.push_back(num);
                ret.push_back(temp);
            }
        }
        return ret;
    }
};
/*
 * Approach: backtracking
 * Note: same as before, too lazy to give the solution
 */