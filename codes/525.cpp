/*
 * Approach: hash-table
 * Time complexity: O(n)   || 88.88% (288 ms)
 * Space complexity: O(n)  || 57.66% (83 MB)
 * Note: 0 -> -1, 1 -> 1, find sum == 0 or same sum at two position
 */
class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int, int> m;
        int ret = 0, sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum += (nums[i] == 0 ? -1 : 1);
            if (sum == 0) ret = i + 1;
            else {
                if (m.count(sum)) ret = max(ret, i - m[sum]);
                else m[sum] = i;
            }
        }
        return ret;
    }
};