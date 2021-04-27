/*
 * Approach: one pass with map
 * Time complexity:  O(n)    || 100.00%
 * Space complexity: O(n)    || 58.03%
 * Note: O(1) space version below
 */
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        if (!nums.size()) return 1;
        int res = 1;
        unordered_map<int, bool> m;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > 0) {
                if (nums[i] == res) res++;
                else {
                    m[nums[i]] = true;
                }
            }
        }
        do {
            if (!m.count(res)) return res;
        } while (res++);
        return res;
    }
};
/*
 * Approach: swap and find empty one
 * Time complexity:  O(n)    || 100.00%
 * Space complexity: O(1)    || 63.73%
 */
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            while (nums[i] > 0 && nums[i] < n && nums[nums[i]-1] != nums[i]) {
                swap(nums[i], nums[nums[i]-1]);
            }
        }
        for (int i = 0; i < n; i++) {
            if (nums[i] != i+1) return i+1;
        }
        return n+1;
    }
};