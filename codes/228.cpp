/*
 * Approach: NO
 * Time complexity: O(n)   || 100.00% (0 ms)
 * Space complexity: O(n)  || 5.92% (7.1 MB)
 */
class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> ret;
        for (int i = 1, j = 0; i <= nums.size(); i++) {
            if (i == nums.size() || nums[i] - 1 != nums[i-1]) {
                if (i - 1 == j) ret.push_back(to_string(nums[j]));
                else ret.push_back(to_string(nums[j]) + "->" + to_string(nums[i-1]));
                j = i;
            }
        }
        return ret;
    }
};