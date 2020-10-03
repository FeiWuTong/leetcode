/*
 * Approach: Recurssion (Fibonacci)
 * Time complexity: O(2^n)   || Time Limit Exceeded
 * Space complexity: O(n)  || -
 */
class Solution {
public:
    int climbStairs(int n) {
        if (n == 1) return 1;
        if (n == 2) return 2;
        return climbStairs(n - 1) + climbStairs(n - 2);
    }
};
/*
 * Approach: DP
 * Time complexity: O(n)   || 100.00%
 * Space complexity: O(1)  || 100.00%
 */
class Solution {
public:
    int climbStairs(int n) {
        if (n == 1) return 1;
        if (n == 2) return 2;
        int n1 = 1, n2 = 2, n3;
        int count = 2;
        while (count < n) {
            n3 = n2;
            n2 += n1;
            n1 = n3;
            count++;
        }
        return n2;
    }
};