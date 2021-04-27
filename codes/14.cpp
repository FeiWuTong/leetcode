/*
 * Approach: Vertical Scanning
 * Time complexity: O(S)  || 98.70%  (S is the sum of all characters in all strings)
 * Space complexity: O(1) || 99.82%
 * Note: Extra methods include "Horizontal scannning", "Divide and conquer" and "Binary search(letters)".
 */
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.size() < 1) return "";
        for (int i = 0; i < strs[0].size(); i++) {
            for (int j = 1; j < strs.size(); j++) {
                if (i == strs[j].size() || strs[j][i] != strs[0][i])
                    return strs[0].substr(0, i);
            }
        }
        return strs[0];
    }
};