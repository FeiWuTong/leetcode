/*
 * Approach: Bi-Search
 * Time complexity: O(log(n))   || 99.65%
 * Space complexity: O(1)       || 100.00%
 */
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1, m;
        vector<int> ans = {-1, -1};
        while (l <= r) {
            m = (l + r) / 2;
            if (nums[m] < target) l = m + 1;
            else if (nums[m] > target) r = m - 1;
            else {
                // left part
                int ll = l, rr = m - 1, mm;
                while (ll <= rr) {
                    mm = (ll + rr) / 2;
                    if (nums[mm] < target) ll = mm + 1;
                    else rr = mm - 1;
                }
                ans[0] = ll;
                // right part
                ll = m + 1, rr = r;
                while (ll <= rr) {
                    mm = (ll + rr) / 2;
                    if (nums[mm] > target) rr = mm - 1;
                    else ll = mm + 1;
                }
                if (ll > r) ans[1] = ll - 1;
                else ans[1] = nums[ll] == target ? ll : ll - 1;
                break;
            }
        }
        return ans;
    }
};