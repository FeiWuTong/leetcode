/*
 * Approach: DP
 * Time complexity: O(w1*w2)   || 72.33%
 * Space complexity: O(w1*w2)  || 87.50%
 */
class Solution {
public:
    int minDistance(string word1, string word2) {
        int nr_w1 = word1.size(), nr_w2 = word2.size();
        vector<vector<int>> dp(nr_w1 + 1, vector<int>(nr_w2 + 1, 0));
        for (int i = 0; i <= nr_w1; i++) {
            dp[i][0] = i;
        }
        for (int j = 0; j <= nr_w2; j++) {
            dp[0][j] = j;
        }
        for (int i = 1; i <= nr_w1; i++) {
            for (int j = 1; j <= nr_w2; j++) {
                // any adjacent value in dp can only diff by 1
                // otherwise dp would no longer be the minimum
                // so is the same as dp[i][j] = min(dp[i - 1][j - 1], dp[i - 1][j] + 1, dp[i][j - 1] + 1)
                if (word1[i-1] == word2[j-1]) {
                    dp[i][j] = dp[i-1][j-1];
                } else {
                    dp[i][j] = min(dp[i-1][j-1], min(dp[i][j-1], dp[i-1][j])) + 1;
                }
            }
        }
        return dp[nr_w1][nr_w2];
    }
};