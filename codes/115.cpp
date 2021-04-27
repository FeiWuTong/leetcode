/*
 * Approach: dp (2d array)
 * Time complexity: O(n^2)   || 24.57% (20 ms)
 * Space complexity: O(n^2)  || 83.33% (13.3 MB)
 */
class Solution {
public:
    int numDistinct(string s, string t) {
        int sizeS = s.size(), sizeT = t.size();
        vector<vector<unsigned long>> dp(sizeS + 1, vector<unsigned long>(sizeT + 1, 0));
        dp[0][0] = 1;
        for (int i = 0; i < sizeS; i++) {
            dp[i+1][0] = 1;
            for (int j = 0; j <= i && j < sizeT; j++) {
                dp[i+1][j+1] = dp[i][j+1] + dp[i][j] * (s[i] == t[j]);
            }
        }
        return dp[sizeS][sizeT];
    }
};
/*
 * Approach: dp (1d array)
 * Time complexity: O(n^2)   || 85.19% (8 ms)
 * Space complexity: O(n)  || 100.00% (6.6 MB)
 */
class Solution {
public:
    int numDistinct(string s, string t) {
        int sizeS = s.size(), sizeT = t.size(), temp;
        vector<unsigned long> dp(sizeT + 1, 0);
        dp[0] = 1;
        for (int i = 1; i <= sizeS; i++) {
            int last = 1;
            for (int j = 1; j <= i && j <= sizeT; j++) {
                temp = dp[j];
                dp[j] = dp[j] + last * (s[i-1] == t[j-1]);
                last = temp;
            }
        }
        return dp[sizeT];
    }
};