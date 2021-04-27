/*
 * Approach: two-pass
 * Time complexity: O(n)   || 100.00%
 * Space complexity: O(1)  || 100.00%
 */
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int r, w, b;
        r = w = b = 0;
        for (int i = 0; i < nums.size(); i++) {
            switch (nums[i]) {
                case 0: r++; break;
                case 1: w++; break;
                default: b++;
            }
        }
        int i = 0;
        while (r--) nums[i++] = 0;
        while (w--) nums[i++] = 1;
        while (b--) nums[i++] = 2;
    }
};
/*
 * Approach: one pass
 * Time complexity: O(n)   || 100.00%
 * Space complexity: O(1)  || 100.00%
 */
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int r = 0, w = 0, b = nums.size() - 1;
        while (w <= b) {
            if (nums[w] == 2) {
                nums[w] = nums[b];
                nums[b] = 2;
                b--;
            } else if (nums[w] == 1) {
                w++;
            } else {
                if (w != r) {
                    nums[w] = nums[r];
                    nums[r] = 0;
                }
                r++;
                w++;
            }
        }
    }
};