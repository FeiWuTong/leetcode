/*
 * Approach: DP (same as #123-#3)
 * Time complexity: O(n^2)   || 9.72% (1232 ms)
 * Space complexity: O(n)  || 5.55% (12 MB)
 * Note: explaination in #123, note that when k is too large we should choose n / 2
 */
class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        if (prices.size() == 0) return 0;
        k = min(k, int(prices.size() / 2));
        vector<int> dp(k + 1, 0), minp(k, prices[0]);
        for (int i = 1; i < prices.size(); i++) {
            for (int j = 1; j <= k; j++) {
                minp[j-1] = min(minp[j-1], prices[i] - dp[j-1]);
                dp[j] = max(dp[j], prices[i] - minp[j-1]);
            }
        }
        return dp[k];
    }
};
/*
 * Approach: DP
 * Time complexity: O(n^2)   || 83.81% (8 ms)
 * Space complexity: O(n)  || 5.55% (12.1 MB)
 * Note: Indeed we calculate _k transactions at most, here _k is peaks' amount
 * Note: And if k >= _k, we add up all peaks-bottom D-value (no need to dp)
 */
class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        if (n < 2) return 0;
        int _k = 0, ret = 0;
        bool asc = false;
        // statis the amount of peaks (_k)
        for (int i = 1; i < n; i++) {
            if (prices[i] > prices[i-1]) {
                if (!asc) asc = true;
                // save all peaks-bottom D-value in advance
                ret += prices[i] - prices[i-1];
            }
            else if (asc && prices[i] < prices[i-1]) asc = false, _k++;
        }
        if (asc) _k++;
        // at most _k peaks so return ret and no need for dp
        if (k >= _k) return ret;
        // k < _k, we should do in dp like #123
        vector<int> dp(k + 1, 0), minp(k, prices[0]);
        for (int i = 1; i < prices.size(); i++) {
            for (int j = 1; j <= k; j++) {
                minp[j-1] = min(minp[j-1], prices[i] - dp[j-1]);
                dp[j] = max(dp[j], prices[i] - minp[j-1]);
            }
        }
        return dp[k];
    }
};