/*
 * Approach: NO
 * Time complexity: O(n^2) || 100.00%
 * Space complexity: O(1)  || 100.00%
 * Note: garbage puzzle
 */
class Solution {
public:
    string countAndSay(int n) {
        string res = "1", tmp;
        int c = 1;
        while (--n) {
            tmp = "";
            for (int i = 0; i < res.size(); i++) {
                if (i != res.size() - 1 && res[i] == res[i+1]) c++;
                else {
                    tmp += '0' + c;
                    tmp += res[i];
                    c = 1;
                }
            }
            res = tmp;
        }
        return res;
    }
};