/*
 * Approach: backtracking
 * Time complexity: -   || 63.75%
 * Space complexity: -  || 100.00%
 */
class Solution {
private:
    int len;
    void backtrack(vector<string>& ret, string& temp, string& s, int start, int count) {
        if (count == 4) {
            if (start == len) ret.push_back(temp.substr(0, temp.size() - 1));
        }
        else {
            if (start == len) return;
            for (int i = 1; i <= 3 && start + i <= len; i++) {
                if (stoi(s.substr(start, i)) > 255 || (s[start] == '0' && i != 1)) continue;
                string temps = temp;
                temp += s.substr(start, i) + ".";
                backtrack(ret, temp, s, start + i, count + 1);
                temp = temps;
            }
        }
    }
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> ret;
        string temp = "";
        len = s.size();
        backtrack(ret, temp, s, 0, 0);
        return ret;
    }
};