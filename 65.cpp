/*
 * Approach: straightforward
 * Time complexity: O(n)   || 70.44%
 * Space complexity: O(1)  || 100.00%
 * Note: No skill in this problem, just garbage
 */
class Solution {
public:
    bool isNumber(string s) {
        int i = 0;
        for (; s[i] == ' '; i++);
        if (s[i] == '+' || s[i] == '-') i++;
        int nr_num, nr_pt;
        for (nr_num = 0, nr_pt = 0; s[i] >= '0' && s[i] <= '9' || s[i] == '.' && nr_pt <= 1; i++) {
            s[i] == '.' ? nr_pt++ : nr_num++;
        }
        if (nr_num < 1 || nr_pt > 1) return false;
        if (s[i] == 'e') {
            i++;
            if (s[i] == '+' || s[i] == '-') i++;
            for (nr_num = 0; s[i] >= '0' && s[i] <= '9'; i++, nr_num++);
            if (nr_num < 1) return false;
        }
        for (; s[i] == ' '; i++);
        return s[i] == '\0';
    }
};