/*
 * Approach: DP
 * Time complexity: O(n)   || 7.82% (16 ms)
 * Space complexity: O(n)  || 5.00% (13.2 MB)
 * Note: dp[i][0] is positive maximum, dp[i][1] is negative minimum
 */
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size(), ret = nums[0];
        if (n < 2) return ret;
        vector<vector<int>> dp(n + 1, vector<int>(2));
        dp[0][0] = -1, dp[0][1] = 1;
        for (int i = 1; i <= n; i++) {
            if (nums[i-1] < 0) {
                dp[i][0] = dp[i-1][1] <= 0 ? dp[i-1][1] * nums[i-1] : -1;
                dp[i][1] = dp[i-1][0] > 0 ? dp[i-1][0] * nums[i-1] : nums[i-1];
            } else if (nums[i-1] == 0) {
                dp[i][0] = dp[i][1] = 0;
            } else {
                dp[i][0] = dp[i-1][0] > 0 ? dp[i-1][0] * nums[i-1] : nums[i-1];
                dp[i][1] = dp[i-1][1] <= 0 ? dp[i-1][1] * nums[i-1] : 1;
            }
        }
        for (int i = 1; i <= n; i++) {
            ret = max(ret, dp[i][0]);
        }
        return ret;
    }
};
/*
 * Approach: DP
 * Time complexity: O(n)   || 40.36% (8 ms)
 * Space complexity: O(1)  || 5.00% (11.8 MB)
 * Note: from above we can find that we just need to store last result, i.e. dp[i-1]
 */
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int ret, lastMin, lastMax, cur1, cur2;
        ret = lastMin = lastMax = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            cur1 = lastMin * nums[i];
            cur2 = lastMax * nums[i];
            lastMin = min(min(cur1, cur2), nums[i]);
            lastMax = max(max(cur1, cur2), nums[i]);
            ret = max(ret, lastMax);
        }
        return ret;
    }
};