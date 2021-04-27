/*
 * Approach: binary search
 * Time complexity: O(lgn)   || 100.00% (0 ms)
 * Space complexity: O(1)  || 43.17% (6 MB)
 */
// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        long long l = 0, m;
        while (l <= n) {
            m = (l + n) >> 1;
            if (isBadVersion(m)) n = m - 1;
            else l = m + 1;
        }
        return n + 1;
    }
};