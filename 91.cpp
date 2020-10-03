/*
 * Approach: DP
 * Time complexity: O(n)   || 100.00%
 * Space complexity: O(n)  || 100.00%
 * Note: 0 cannot be the first num
 */
class Solution {
public:
    int numDecodings(string s) {
        if (s.size() == 0 || s[0] == '0') return 0;
        vector<int> dp(s.size() + 1, 1);
        for (int i = 1; i < s.size(); i++) {
            if (s[i] == '0') {
                if (s[i-1] == '0' || s[i-1] > '2') return 0;
                else dp[i+1] = dp[i-1];
            }
            else dp[i+1] = dp[i] + (s[i-1] < '2' && s[i-1] > '0' || s[i-1] == '2' && s[i] <= '6' ? dp[i-1] : 0);
        }
        return dp[s.size()];
    }
};