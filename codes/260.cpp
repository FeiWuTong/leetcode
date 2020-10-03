/*
 * Approach: bit-manipulation
 * Time complexity: O(n)   || 89.79% (16 ms)
 * Space complexity: O(1)  || 41.05% (10.2 MB)
 * Note: due to 2 different numbers, at least 1-bit is different (xor = 1), which can devide two numbers into two groups
 * Note: any 1-bit which can devide two distinct numbers is ok, in case two &= -two will leave the rightmost 1-bit
 */
class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        // 1: two nums xor result
        int two = accumulate(nums.begin(), nums.end(), 0, bit_xor<int>());
        // 2: divide into 2 groups
        two &= -two; // get 1-bit (for split)
        vector<int> ret(2, 0);
        for (int num : nums) {
            ret[!(num & two)] ^= num;
        }
        return ret;
    }
};