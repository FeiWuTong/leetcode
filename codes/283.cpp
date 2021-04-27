/*
 * Approach: in-place + two pointers
 * Time complexity: O(n)   || 57.11% (12 ms)
 * Space complexity: O(1)  || 60.49% (9 MB)
 */
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int p1 = 0, p2 = 0;
        while (p2 < nums.size()) {
            if (nums[p2] != 0) nums[p1++] = nums[p2];
            p2++;
        }
        while (p1 < p2) nums[p1++] = 0;
    }
};
// optimized to 93.21% (8 ms), 58.66% (9 MB)
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int p1 = 0, p2 = 0;
        while (p2 < nums.size() && p1 == p2 && nums[p2] != 0) p1++, p2++;
        while (p2 < nums.size()) {
            if (nums[p2] != 0) nums[p1++] = nums[p2];
            p2++;
        }
        if (p1 == 0) return;
        while (p1 < p2) nums[p1++] = 0;
    }
};