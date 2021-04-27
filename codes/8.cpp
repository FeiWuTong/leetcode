/*
 * Approach: atoi
 * Time complexity: O(1)  || 92.30%
 * Space complexity: O(1) || 100.00%
 */
class Solution {
public:
    int myAtoi(string str) {
        if (str.empty()) {
            return 0;
        }
        int ans = 0, i = 0, f = 1, b;
        while (isspace(str[i]) && i + 1 < str.size()) {
            i++;
        }
        if (str[i] == '-' || str[i] == '+') {
            f = 44 - str[i++];
        }
        while (i < str.size()) {
            if (isdigit(str[i])) {
                b = str[i++] - '0';
                if (ans >= INT_MAX / 10) {
                    if (ans == INT_MAX / 10) {
                        if (f == 1 && b >= 7) {
                            return INT_MAX;
                        }
                        else if (f == -1 && b >= 8) {
                            return INT_MIN;
                        }
                        else {
                            ans = ans * 10 + b;
                        }
                    }
                    else {
                        return f == 1 ? INT_MAX : INT_MIN;
                    }
                }
                else {
                    ans = ans * 10 + b;
                }
            }
            else {
                return ans * f;
            }
        }
        return ans * f;
    }
};