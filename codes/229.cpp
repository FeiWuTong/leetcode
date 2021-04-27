/*
 * Approach: Moore voting (refer to #169-#last-one)
 * Time complexity: O(n)   || 36.34% (32 ms)
 * Space complexity: O(1)  || 60.44% (15.5 MB)
 * Note: at most 2 majority elements
 */
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int cnt1 = 0, cnt2 = 0, m1, m2;
        // 1: find 2 most elements (O(n))
        for (int n : nums) {
            if (cnt1 && m1 == n) cnt1++;
            else if (cnt2 && m2 == n) cnt2++;
            else if (cnt1 && cnt2) cnt1--, cnt2--;
            else {
                if (!cnt1) m1 = n, cnt1++;
                else m2 = n, cnt2++;
            }
        }
        // 2: check whether more than 1/3
        cnt1 = cnt2 = 0;
        for (int n : nums) {
            if (n == m1) cnt1++;
            else if (n == m2) cnt2++;
        }
        // 3: push result
        vector<int> ret;
        if (cnt1 > nums.size() / 3) ret.push_back(m1);
        if (cnt2 > nums.size() / 3) ret.push_back(m2);
        return ret;
    }
};