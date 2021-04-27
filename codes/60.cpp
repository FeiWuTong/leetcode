/*
 * Approach: DP-like
 * Time complexity: O(n)   || 100.00%
 * Space complexity: O(n)  || 100.00%
 * Note: use fact('n-1') to select first num, fact('n-2') to second...
 */
class Solution {
public:
    string getPermutation(int n, int k) {
        string ret;
        vector<int> num;
        for (int i = 1; i < 10; i++) {
            num.push_back(i);
        }
        int factorial = 1;
        for (int i = 2; i < n; i++) factorial *= i;

        int jump;
        for (int i = n - 1; i > 0; i--) {
            jump = (k - 1) / factorial;
            ret.push_back('0' + num[jump]);
            num.erase(num.begin() + jump);
            if (k >= factorial) k -= jump * factorial;
            factorial /= i;
        }
        ret.push_back('0' + num[0]);
        return ret;
    }
};