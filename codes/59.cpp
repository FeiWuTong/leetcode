/*
 * Approach: Straightforward
 * Time complexity: O(n^2)   || 100.00%
 * Space complexity: O(n^2)  || 100.00%
 * Note: decompose to 4 part in one round, left to right, top to bottom and so on.
 */
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> res(n, vector<int>(n));
        int num = 1, round = 0;
        while (num <= n*n) { // every round l2r, t2b, r2l, b2t
            int step = round;
            while (step < n - round) res[round][step++] = num++;
            step = round + 1;
            while (step < n - round) res[step++][n-round-1] = num++;
            step = n - round - 2;
            while (step > round) res[n-round-1][step--] = num++;
            step = n - round - 1;
            while (step > round) res[step--][round] = num++;
            round++;
        }
        return res;
    }
};