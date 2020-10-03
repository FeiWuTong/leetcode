/*
 * Approach: one-pass
 * Time complexity: O(n)   || 23.09% (12 ms)
 * Space complexity: O(1)  || 5.51% (13.2 MB)
 * Note: check maximum profit when the minimum price change
 */
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ret = 0;
        int minp, maxp;
        for (int i = 0; i < prices.size(); i++) {
            if (i == 0) minp = maxp = prices[i];
            else {
                if (prices[i] < minp) {
                    ret = max(ret, maxp - minp);
                    minp = maxp = prices[i];
                }
                else if (prices[i] > maxp) maxp = prices[i];
            }
        }
        ret = max(ret, maxp - minp);
        return ret;
    }
};
/*
 * Approach: one-pass concise
 * Time complexity: O(n)   || 23.09% (12 ms)
 * Space complexity: O(1)  || 5.51% (13.1 MB)
 */
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ret = 0;
        int minp = INT_MAX;
        for (int i = 0; i < prices.size(); i++) {
            if (prices[i] < minp) minp = prices[i];
            else if (prices[i] - minp > ret) ret = prices[i] - minp;
        }
        return ret;
    }
};