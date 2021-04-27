/*
 * Approach: No
 * Time complexity: O(log10(x))  || 99.88%
 * Space complexity: O(1) || 99.14%
 * Note: Stores Symbol and Value in array can use less code, but costs more space.
 */
class Solution {
public:
    string intToRoman(int num) {
        string ret = "";
        int rem;
        rem = num % 1000;
        num /= 1000;
        while (num--) { ret += "M"; }
        num = rem;
        rem %= 100;
        num /= 100;
        if (num == 9) { ret += "CM"; }
        else if (num == 4) { ret += "CD"; }
        else {
            if (num >= 5) {
                num -= 5;
                ret += "D";
            }
            while (num--) { ret += "C"; }
        }
        num = rem;
        rem %= 10;
        num /= 10;
        if (num == 9) { ret += "XC"; }
        else if (num == 4) { ret += "XL"; }
        else {
            if (num >= 5) {
                num -= 5;
                ret += "L";
            }
            while (num--) { ret += "X"; }
        }
        if (rem == 9) { ret += "IX"; }
        else if (rem == 4) { ret += "IV"; }
        else {
            if (rem >= 5) {
                rem -= 5;
                ret += "V";
            }
            while (rem--) { ret += "I"; }
        }
        return ret;
    }
};