/*
 * Approach: Two Pointer Moving Window
 * Time complexity: O(n)  || 98.37%
 * Space complexity: O(1) || 99.58%
 * Note: Brute Force is O(n^2) time and O(1) space.
 */
class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxa = 0, l = 0, r = height.size() - 1;
        while (l < r) {
            maxa = max(maxa, min(height[l], height[r])*(r-l));
            height[l] < height[r] ? l++ : r--;
        }
        return maxa;
    }
};