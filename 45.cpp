/*
 * Approach: Greedy (with jump max to reduce time)
 * Time complexity:  O(n)    || 94.44%
 * Space complexity: O(1)    || 66.25%
 */
class Solution {
public:
    int jump(vector<int>& nums) {
        int maxx = 0, maxi = 0, step = 0;
        for (int i = 0; i < nums.size()-1; i++) {
            maxx = maxx < i + nums[i] ? i + nums[i] : maxx;
            if (i == maxi) {
                step++;
                maxi = maxx;
            }
        }
        return step;
    }
};
/*
 * Approach: BFS (similar to above)
 * Time complexity:  O(n)    || 99.51%
 * Space complexity: O(1)    || 77.10%
 */
class Solution {
public:
    int jump(vector<int>& nums) {
        if (nums.size() < 2) return 0;
        int level = 0, curMax = 0, i = 0, nextMax = 0;
        while (curMax - i + 1 > 0) {
            level++;
            for (; i <= curMax; i++) {
                nextMax = max(nextMax, nums[i]+i);
                if (nextMax >= nums.size()-1) return level;
            }
            curMax = nextMax;
        }
        return -1;
    }
};