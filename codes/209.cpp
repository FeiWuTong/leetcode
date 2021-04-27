/*
 * Approach: two pointers
 * Time complexity: O(n)   || 58.19% (16 ms)
 * Space complexity: O(1)  || 65.05% (10.4 MB)
 */
class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int cnt = 0, n = nums.size();
        for (int i = 0, j = 0, a = 0; i < n;) {
            // front pointer
            while (i < n && a < s) a += nums[i++];
            if (i == n && a < s) break;
            cnt = cnt ? min(i - j, cnt) : i - j;
            // behind pointer
            while (a >= s) a -= nums[j++];
            cnt = min(i - j + 1, cnt);
            if (cnt == 1) return 1;
        }
        return cnt;
        /*
        int n = nums.size(), cnt = n + 1;
        for (int i = 0, j = 0, a = 0; i < n;) {
            while (i < n && a < s) a += nums[i++];
            if (a >= s) {
                do {
                    a -= nums[j++];
                } while (a >= s);
                cnt = min(i - j + 1, cnt);
                if (cnt == 1) return 1;
            }
        }
        return cnt == n + 1 ? 0 : cnt;
        */
    }
};
/*
 * Approach: bi-search
 * Time complexity: O(nlogn)   || 17.83% (24 ms)
 * Space complexity: O(n)  || 8.60% (10.8 MB)
 */
class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int n = nums.size(), len = INT_MAX;
        // sums is ascending array
        vector<int> sums(n + 1, 0);
        for (int i = 1; i <= n; i++) {
            sums[i] = sums[i - 1] + nums[i - 1];
        }
        for (int i = n; i > 0 && sums[i] >= s; i--) {
            // bi-search for shortest subarray with sum >= s
            int j = upper_bound(sums.begin(), sums.begin() + i + 1, sums[i] - s) - sums.begin();
            len = min(len, i - j + 1);
        }
        return len == INT_MAX ? 0 : len;
    }
};