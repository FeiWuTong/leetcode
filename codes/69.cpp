/*
 * Approach: NO
 * Time complexity: O(log(n))   || 6.26% (88 ms)
 * Space complexity: O(1)  || 100.00%
 */
class Solution {
public:
    int mySqrt(int x) {
        int i = 1;
        for (; i <= x / i; i++);
        return i - 1;
    }
};
/*
 * Approach: bi-search
 * Time complexity: O(log(log(n)))   || 58.19% (4 ms)
 * Space complexity: O(1)  || 100.00%
 */
class Solution {
public:
    int mySqrt(int x) {
        if (x == 0) return 0;
        if (x < 4) return 1;
        int left = 0, right = x / 2, mid;
        while (left <= right) {
            mid = (left + right) >> 1;
            if (mid == x / mid) return mid;
            else if (mid < x / mid) left = mid + 1;
            else right = mid - 1;
        }
        return right;
    }
};
/*
 * Approach: Newton-iterative
 * Time complexity: -   || 100.00% (0 ms)
 * Space complexity: O(1)  || 100.00%
 * Note: `double` ans is also right
 */
class Solution {
public:
    int mySqrt(int x) {
        if (x == 0) return 0;
        if (x == 1) return 1;
        int ans = x >> 1;
        while (x / ans < ans) ans = (ans + x / ans) / 2;
        return ans;
    }
};