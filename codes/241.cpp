/*
 * Approach: devide and conquer (recursive)
 * Time complexity: -   || 49.16% (8 ms)
 * Space complexity: -  || 11.60% (12.3 MB)
 */
class Solution {
public:
    vector<int> diffWaysToCompute(string input) {
        vector<int> ret;
        for (int i = 0; i < input.size(); i++) {
            char c = input[i];
            if (ispunct(c)) {
                for (int a : diffWaysToCompute(input.substr(0, i))) {
                    for (int b : diffWaysToCompute(input.substr(i + 1))) {
                        ret.push_back(c == '+' ? a + b : c == '-' ? a - b : a * b);
                    }
                }
            }
        }
        return ret.size() ? ret : vector<int>{stoi(input)};
    }
};
/*
 * Approach: dp
 * Time complexity: -   || 77.14% (4 ms)
 * Space complexity: -  || 93.98% (7.1 MB)
 * Note: just save intermediate result to avoid repeated recursive
 */
class Solution {
private:
    unordered_map<string, vector<int>> dp;
public:
    vector<int> diffWaysToCompute(string input) {
        vector<int> ret;
        for (int i = 0; i < input.size(); i++) {
            char c = input[i];
            if (c == '+' || c == '-' || c == '*') {
                vector<int> r1, r2;

                string temps = input.substr(0, i);
                if (dp.count(temps)) r1 = dp[temps];
                else r1 = diffWaysToCompute(temps);

                temps = input.substr(i + 1);
                if (dp.count(temps)) r2 = dp[temps];
                else r2 = diffWaysToCompute(temps);

                for (int a : r1) {
                    for (int b : r2) {
                        ret.push_back(c == '+' ? a + b : c == '-' ? a - b : a * b);
                    }
                }
            }
        }
        if (ret.size() == 0) ret.push_back(stoi(input));
        dp[input] = ret;
        return ret;
    }
};