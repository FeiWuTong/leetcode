/*
 * Approach: hashtable
 * Time complexity: O(n)   || 18.19% (88 ms)
 * Space complexity: O(n)  || 51.89% (16.4 MB)
 */
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        if (k >= nums.size()) return false;
        unordered_map<int, int> table;
        for (int i = 0; i < nums.size(); i++) {
            if (table.count(nums[i])) {
                if (i - table[nums[i]] <= k) return true;
            }
            table[nums[i]] = i;
        }
        return false;
    }
};
/*
 * Approach: hashtable (set not map)
 * Time complexity: O(n)   || 54.96% (52 ms)
 * Space complexity: O(k)  || 50.89% (16.4 MB)
 */
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_set<int> check;
        if (k <= 0) return false;

        for (int i = 0; i < nums.size(); i++) {
            if (i > k) check.erase(nums[i-k-1]);
            if (check.count(nums[i])) return true;
            check.insert(nums[i]);
        }
        return false;
    }
};