/*
 * Approach: bit manipulation (3 xor = 0)
 * Time complexity: O(n)   || 48.68% (16 ms)
 * Space complexity: O(1)  || 100.00% (9.6 MB)
 * Note: use 2 bits (one, two) to represent status, i.e. 00 01 10 (11 is abolished)
 * Note: think `one` is 1 xor, i.e. include the num 1 time, recording as xor-num
 * Note: think `two` is 2 xor, i.e. include the num 2 time, recording as xor-num samely
 * Note: then we can write code as `one = (one ^ nums[i])`, `two = (two ^ nums[i])`
 * Note: but pay attention, when `two` is existing, then another `one` means 3 xor, so the status return to 00
 * Note: so we can use ~two to get whether `two` is existing, and use & to make one return 0 or not
 * Note: `two` is the same, when `one` is existing, then two should exclude that 1-xor-num (& ~one)
 * Note: when `one` is not existing (that means 2-xor-num), then two should include that 2-xor-num (& ~one)
 */
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int one = 0, two = 0;
        for (int i = 0; i < nums.size(); i++) {
            one = (one ^ nums[i]) & ~two;
            two = (two ^ nums[i]) & ~one;
        }
        return one;
    }
};
// Note: even a number appears 5 times at most, we can also use one, two, three 3 bits to represent status
// Note: loop is 000 -> 100 -> 010 -> 110 -> 001 -> 000
// Note: samely, `one` change as: 0 -> 1 -> 0 -> 1 -> 0 -> 0, last one change is `three` = 1
// Note: same as `two` and `three`, just find regularity and use logical expression
// NOte: most importantly, `one` should be (one ^ nums[i]) to record num
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int one = 0, two = 0, three = 0;
        for (int i = 0; i < nums.size(); i++) {
            two = two ^ (nums[i] & one);                // 01100 - 0...
            one = (one ^ nums[i]) & ~three;             // 10100 - 1...
            three = three ^ (nums[i] & ~one & ~two);    // 00010 - 0...
        }
        return one;
    }
};
// or
// just make `one` keep a length 5 loop: 10010 (1 represents xor)
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int one = 0, two = 0, three = 0, four = 0;
        for (int i = 0; i < nums.size(); i++) {
            one = (one ^ nums[i]) & ~four;      // 10010 - 1...
            two = (two ^ nums[i]) & ~one;       // 01001 - 0...
            three = (three ^ nums[i]) & ~two;   // 10100 - 1...
            four = (four ^ nums[i]) & ~three;   // 01010 - 0...
        }
        return one;
    }
};