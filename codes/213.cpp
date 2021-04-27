/*
 * Approach: DP (Refer to #198)
 * Time complexity: O(n)   || 100.00% (0 ms)
 * Space complexity: O(1)  || 66.10% (7.7 MB)
 * Note: due to nums[0] adjacent to nums[n-1], we can make 2 dp
 * Note: one is nums[0]-nums[n-2], the other is nums[1]-nums[n-1]
 */
class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        if (nums.size() == 1) return nums[0];
        int dp[2] = {0};
        for (int i = 0; i < nums.size() - 1; i++) {
            dp[i%2] = max(dp[i%2] + nums[i], dp[(i+1)%2]);
        }
        int ret = max(dp[0], dp[1]);
        dp[0] = dp[1] = 0;
        for (int i = 1; i < nums.size(); i++) {
            dp[i%2] = max(dp[i%2] + nums[i], dp[(i+1)%2]);
        }
        ret = max(ret, max(dp[0], dp[1]));
        return ret;
    }
};