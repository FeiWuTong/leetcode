/*
 * Approach: bit manipulation (xor)
 * Time complexity: O(n)   || 31.93% (24 ms)
 * Space complexity: O(1)  || 6.17% (12.2 MB)
 * Note: Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?
 */
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ret = nums[0];
        for (int i = 1; i < nums.size(); i++) ret ^= nums[i];
        return ret;
    }
};