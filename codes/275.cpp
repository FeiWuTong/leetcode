/*
 * Approach: sorted and binary search (refer to 274 #1)
 * Time complexity: O(logn)   || 92.81% (36 ms)
 * Space complexity: O(1)  || 93.93% (18.6 MB)
 */
class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        int l = 0, r = n, m;
        while (l < r) {
            m = (l + r) >> 1;
            if (citations[m] > n - m) r = m;
            else if (citations[m] == n - m) return n - m;
            else l = m + 1;
        }
        return n - r;
    }
};