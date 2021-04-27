/*
 * Approach: dp (Fibonacci-like)
 * Time complexity: O(n^2)   || 100.00%
 * Space complexity: O(n)  || 100.00%
 */
class Solution {
public:
    int numTrees(int n) {
        vector<int> dp(n + 1, 0);
        dp[0] = dp[1] = 1;
        for (int i = 2; i <= n; i++) {
            for (int j = 1; j <= i / 2; j++) {
                dp[i] += dp[i-j] * dp[j-1];
            }
            dp[i] *= 2;
            if (i % 2) dp[i] += dp[i/2] * dp[i/2];
        }
        return dp[n];
    }
};