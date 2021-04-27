/*
 * Approach: ordered-set (refer to #219-#2)
 * Time complexity: O(nlogk)   || 17.76% (40 ms)
 * Space complexity: O(k)  || 44.38% (11.2 MB)
 * Note1: should deal with edge case: overflow
 * Note2: why is unnecessary to use multiset? If we meet a same num in window,
 * Note2: we will quit and return true before insertion. If t < 0, we will never return true
 */
class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        // <set> uses red-black tree, so it is ordered automatically
        set<long long> window;
        for (int i = 0; i < nums.size(); i++) {
            // O(logk)
            if (i > k) window.erase(nums[i-k-1]);
            // O(logk), we need to find out an element x satisfy nums[i] - t <= x <= nums[i] + t
            auto pos = window.lower_bound((long long)nums[i] - t);
            if (pos != window.end() && *pos - nums[i] <= t) return true;
            // O(logk)
            window.insert(nums[i]);
        }
        return false;
    }
};
// set<int> another way to deal with overflow
class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        if (t < 0) return false;
        set<int> window;
        for (int i = 0, bound; i < nums.size(); i++) {
            if (i > k) window.erase(nums[i-k-1]);
            if (nums[i] <= INT_MIN + t) bound = INT_MIN;
            else bound = nums[i] - t;
            auto pos = window.lower_bound(bound);
            if (pos != window.end()) {
                if (nums[i] >= INT_MAX - t) bound = INT_MAX;
                else bound = nums[i] + t;
                if (*pos <= bound) return true;
            }
            window.insert(nums[i]);
        }
        return false;
    }
};
/*
 * Approach: vector-sort for window-t
 * Time complexity: O(n^2)   || 72.85% (24 ms)
 * Space complexity: O(n)  || 69.08% (10 MB)
 * Note: former is window-k, this one is window-t
 * Note: just for set.insert is time-spending
 */
class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        int n = nums.size();
        vector<pair<long long, int> > check(n);
        for (int i = 0; i < n; i++) check[i] = {nums[i], i};
        sort(check.begin(), check.end());
        for (int i = 0; i < n - 1; i++) {
            for (int j = i + 1; j < n && check[j].first - check[i].first <= t; j++) {
                if (abs(check[j].second - check[i].second) <= k) return true;
            }
        }
        return false;
    }
};