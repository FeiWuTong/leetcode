/*
 * Approach: deque
 * Time complexity: O(n)   || 52.94% (92 ms)
 * Space complexity: O(k)  || 62.23% (27.4 MB)
 */
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ret(nums.size()-k+1);
        deque<int> dq;
        for (int i = 0, j = 0; i < nums.size(); i++) {
            if (!dq.empty() && dq.front() == i - k) dq.pop_front();
            // keep elements in dq bigger than nums[i]
            while (!dq.empty() && nums[dq.back()] <= nums[i]) dq.pop_back();
            dq.push_back(i);
            if (i >= k - 1) ret[j++] = nums[dq.front()];
        }
        return ret;
    }
};