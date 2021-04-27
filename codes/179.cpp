/*
 * Approach: string-sort
 * Time complexity: O(knlogn)   || 96.09% (8 ms)
 * Space complexity: O(n)  || 9.09% (11.3 MB)
 */
class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string> strnums(nums.size());
        for (int i = 0; i < nums.size(); i++) {
            strnums[i] = to_string(nums[i]);
        }
        // comparation takes O(k) time, sort O(nlogn)
        sort(strnums.begin(), strnums.end(), [](string &s1, string &s2) {
            return s1 + s2 > s2 + s1;
        });
        if (strnums.size() > 1 && strnums[0] == "0") return "0";
        string ret;
        for (string s : strnums) {
            ret += s;
        }
        return ret;
    }
};