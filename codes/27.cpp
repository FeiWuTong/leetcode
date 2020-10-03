/*
 * Approach: Same as 26
 * Time complexity: O(n)   || 100.00%
 * Space complexity: O(1)  || 100.00%
 */
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int i = 0;
        int n = nums.size();
        while (i < n) {
            if (nums[i] == val) {
                nums[i] = nums[n-1];
                n--;
            }
            else i++;
        }
        return n;
    }
};