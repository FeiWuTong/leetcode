/*
 * Approach: NO
 * Time complexity: O(n)   || 77.07%
 * Space complexity: O(n)  || 100.00%
 */
class Solution {
public:
    string addBinary(string a, string b) {
        int na = a.size() - 1;
        int nb = b.size() - 1;
        int nl, nh;
        string ret;
        char flag = '0';
        if (na > nb) {
            nl = nb;
            nh = na;
            ret = a;
        }
        else {
            nl = na;
            nh = nb;
            ret = b;
        }
        for (int i = 0; i <= nl; i++) {
            if (a[na-i] == b[nb-i]) {
                ret[nh-i] = flag;
                flag = a[na-i];
            }
            else {
                if (flag == '1') {
                    ret[nh-i] = '0';
                }
                else {
                    ret[nh-i] = '1';
                }
            }
        }
        if (flag == '1') {
            for (int i = nh - nl - 1; i >= 0; i--) {
                ret[i] = '0' + ('1' - ret[i]);
                if (ret[i] == '1') {
                    flag = '0';
                    break;
                }
            }
            if (flag == '1') {
                ret.insert(0, "1");
            }
        }
        return ret;
    }
};