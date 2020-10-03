/*
 * Approach: Backtracking (recursion)
 * Time complexity: O(3^N * 4^M)   || 100.00%
 * Space complexity: O(3^N * 4^M)  || 87.50%
 * Note: Without recutsion can be more efficient.(latter's space less than 98.00%)
 */
class Solution {
public:
    vector<string> res;
    const vector<string> phone = { "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz" };
    vector<string> letterCombinations(string digits) {
        if (digits.size() != 0) backtrack("", digits);
        return res;
    }
    void backtrack(string comb, string remain) {
        if (remain.size() == 0) res.push_back(comb);
        else {
            int num = remain[0]-'0';
            string letters = phone[num];
            for (int i = 0; i < letters.size(); i++) {
                backtrack(comb+letters[i], remain.substr(1));
            }
        }
    }
};

/*
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> res;
        if (digits.size() == 0) return res;
        vector<string> phone = { "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz" };
        res.push_back("");
        for (int i = 0; i < digits.size(); i++) {
            vector<string> tmp;
            for (int j = 0; j < res.size(); j++) {
                for (auto l : phone[digits[i]-'0']) {
                    tmp.push_back(res[j]+l);
                }
            }
            res.swap(tmp);
        }
        return res;
    }
};
*/