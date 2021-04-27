/*
 * Approach: One-pass Hash Table
 * Time complexity: O(n)  || 90.38%
 * Space complexity: O(n) || 56.22%
 * Note: Maybe use index instead of iterator can speed up a little.
 */
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        unordered_map<int, int> m;
        vector<int> res;
        for (vector<int>::iterator it = nums.begin(); it != nums.end(); it++) {
            int com = target - *it;
            if (m.find(com) != m.end()) {
                res.push_back(m[com]);
                res.push_back(it-nums.begin());
                return res;
            }
            m[*it] = it - nums.begin();
        }
        return res;
    }
};