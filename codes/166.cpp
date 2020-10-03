/*
 * Approach: No
 * Time complexity: -   || 41.78% (4 ms)
 * Space complexity: -  || 100.00% (6.7 MB)
 * Note: sign / overflow should be token into consideration
 */
class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        // edge cases + initiate part (including integer part and point)
        if (numerator == 0) return "0";
        string ret;
        if (numerator > 0 ^ denominator > 0) ret += '-';
        long long n = llabs(numerator), d = llabs(denominator), remain = n % d;
        ret += to_string(n / d);
        if (remain == 0) return ret;
        ret += '.';
        unordered_map<long long, int> pos;
        // decimal part
        while (remain) {
            if (pos.count(remain)) {
                ret.insert(pos[remain], "(");
                ret += ')';
                break;
            }
            pos[remain] = ret.size();
            remain *= 10;
            ret += to_string(remain / d);
            remain %= d;
        }
        return ret;
    }
};