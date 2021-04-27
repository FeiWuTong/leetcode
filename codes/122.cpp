/*
 * Approach: one pass
 * Time complexity: O(n)   || 18.12% (12 ms)
 * Space complexity: O(1)  || 6.35% (13 MB)
 */
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ret = 0;
        for (int i = 1; i < prices.size(); i++) {
            if (prices[i] > prices[i-1]) ret += prices[i] - prices[i-1];
        }
        return ret;
    }
};