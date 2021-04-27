/*
 * Approach: one pass
 * Time complexity: O(n)   || 31.72% (12 ms)
 * Space complexity: O(1)  || 7.14% (13.2 MB)
 * Note: Just like #121, first transaction get the maximum profit
 * Note: And use the first profit as the stake to buy second stock
 * Note: Now the second stock 'buy price' will be update (even be negative)
 * Note: And we do #121 again to get the maximum profit
 */
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy1 = INT_MAX, buy2 = INT_MAX;
        int earn1 = 0, earn2 = 0;
        for (int i = 0; i < prices.size(); i++) {
            buy1 = min(buy1, prices[i]);
            earn1 = max(earn1, prices[i] - buy1);
            buy2 = min(buy2, prices[i] - earn1);
            earn2 = max(earn2, prices[i] - buy2);
        }
        return earn2;
    }
};
/*
 * Approach: dp
 * Note: Profit of k transactions, on i-th day
 * Note: dp[k, i] = max(dp[k, i-1], prices[i] - prices[j] + dp[k-1, j-1]), j=[0..i-1]
 */
/* #1
 * Time complexity: O(kn^2)   || Time Limit Exceeded
 * Space complexity: O(kn)  || -
 */
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() == 0) return 0;
        vector<vector<int>> dp(3, vector<int>(prices.size(), 0));
        for (int k = 1; k <= 2; k++) {
            for (int i = 1; i < prices.size(); i++) {
                int minp = prices[0];
                for (int j = 1; j <= i; j++) {
                    minp = min(minp, prices[j] - dp[k-1][j-1]);
                }
                dp[k][i] = max(dp[k][i-1], prices[i] - minp);
            }
        }
        return dp[2][prices.size() - 1];
    }
};
/* #2
 * Time complexity: O(kn)   || 91.84% (16 ms)
 * Space complexity: O(kn)  || 97.30% (13.8 MB)
 * Note: in #1, min is repeated calculated
 */
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() == 0) return 0;
        vector<vector<int>> dp(3, vector<int>(prices.size(), 0));
        for (int k = 1; k <= 2; k++) {
            int minp = prices[0];
            for (int i = 1; i < prices.size(); i++) {
                minp = min(minp, prices[i] - dp[k-1][i-1]);
                dp[k][i] = max(dp[k][i-1], prices[i] - minp);
            }
        }
        return dp[2][prices.size() - 1];
    }
};
/* #3
 * Time complexity: O(kn)   || 98.19% (4 ms)
 * Space complexity: O(k)  || 7.14% (13.1 MB)
 * Note: only need k `min` for each transaction
 * Note: and k dp for recording k-1's maximum profit
 * Note: We can understand minp like this: minp[k] means after finishing k-1 transactions, we earn some profits, and use the profits as discount for stock price in k-th transaction
 */
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() == 0) return 0;
        vector<int> dp(3, 0), minp(3, prices[0]);
        for (int i = 1; i < prices.size(); i++) {
            for (int k = 1; k <= 2; k++) {
                minp[k] = min(minp[k], prices[i] - dp[k-1]);
                dp[k] = max(dp[k], prices[i] - minp[k]);
            }
        }
        return dp[2];
    }
};