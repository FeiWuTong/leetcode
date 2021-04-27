/*
 * Approach: No
 * Time complexity: O(log10(x))  || 97.46%
 * Space complexity: O(1) || 99.27%
 * Note: Stores Symbol and Value in array can use less code, but costs more space.
 */
class Solution {
public:
    int romanToInt(string s) {
        int ret = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == 'M') { ret += 1000; }
            else if (s[i] == 'D') { ret += 500; }
            else if (s[i] == 'C') {
                if (i + 1 < s.size()) {
                    if (s[i+1] == 'M') {
                        ret += 900;
                        i++;
                    }
                    else if (s[i+1] == 'D') {
                        ret += 400;
                        i++;
                    }
                    else { ret += 100; }
                }
                else { ret += 100; }
            }
            else if (s[i] == 'L') { ret += 50; }
            else if (s[i] == 'X') {
                if (i + 1 < s.size()) {
                    if (s[i+1] == 'C') {
                        ret += 90;
                        i++;
                    }
                    else if (s[i+1] == 'L') {
                        ret += 40;
                        i++;
                    }
                    else { ret += 10; }
                }
                else { ret += 10; }
            }
            else if (s[i] == 'V') { ret += 5; }
            else {
                if (i + 1 < s.size()) {
                    if (s[i+1] == 'X') {
                        ret += 9;
                        i++;
                    }
                    else if (s[i+1] == 'V') {
                        ret += 4;
                        i++;
                    }
                    else { ret += 1; }
                }
                else { ret += 1; }
            }
        }
        return ret;
    }
};