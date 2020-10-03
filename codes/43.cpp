/*
 * Approach: Multiply String
 * Time complexity:  O(n)    || 99.32%
 * Space complexity: O(n)    || 71.33%
 */
class Solution {
public:
    string multiply(string num1, string num2) {
        int n1 = num1.length(), n2 = num2.length();
        vector<int> pos(n1+n2, 0);
        for (int i = n1-1; i >= 0; i--) {
            for (int j = n2-1; j >= 0; j--) {
                int mul = (num1[i]-'0') * (num2[j]-'0');
                int sum = mul + pos[i+j+1];
                pos[i+j] += sum / 10;
                pos[i+j+1] = sum % 10;
            }
        }
        string res = "";
        for (int p : pos) if (!(!res.length() && !p)) res += p + '0';
        return res.length() ? res : "0";
    }
};