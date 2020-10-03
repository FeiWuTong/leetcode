/*
 * Approach: in-place (cyclic replacements)
 * Time complexity: O(n)   || 89.95% (8 ms)
 * Space complexity: O(1)  || 8.33% (10 MB)
 * Note: all elements will only move 1 time
 */
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size(), next;
        for (int i = 0, cnt = 0; cnt < n; i++) {
            int cur = i, prev = nums[i];
            do {
                next = (cur + k) % n;
                swap(prev, nums[next]);
                cur = next;
                cnt++;
            } while (cur != i);
        }
    }
};
/*
 * Approach: reverse
 * Time complexity: O(n)   || 89.95% (8 ms)
 * Space complexity: O(1)  || 25.00% (9.8 MB)
 */
class Solution {
private:
    void reverse(vector<int>& nums, int i, int j) {
        while (i < j) {
            swap(nums[i], nums[j]);
            i++, j--;
        }
    }
public:
    void rotate(vector<int>& nums, int k) {
        k %= nums.size();
        reverse(nums, 0, nums.size() - 1);
        reverse(nums, 0, k - 1);
        reverse(nums, k, nums.size() - 1);
    }
};