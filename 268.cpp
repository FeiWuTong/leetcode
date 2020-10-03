/*
 * Approach: bit-manipulation (xor)
 * Time complexity: O(n)   || 82.55% (40 ms)
 * Space complexity: O(1)  || 92.95% (18 MB)
 * Note: missing number will only xor 1 time
 */
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int miss = nums.size();
        for (int i = 0; i < nums.size(); i++) {
            miss ^= i;
            miss ^= nums[i];
        }
        return miss;
    }
};
/*
 * Approach: math (Gauss' Formula)
 * Time complexity: O(n)   || 82.55% (40 ms)
 * Space complexity: O(1)  || 73.93% (18 MB)
 * Note: only miss 1 num, find the D-value between expect sum and actual sum
 */
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        return (nums.size() * (nums.size() + 1) >> 1) - accumulate(nums.begin(), nums.end(), 0);
    }
};