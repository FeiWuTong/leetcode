/*
 * Approach: hashtable
 * Time complexity: O(n)   || 52.82% (68 ms)
 * Space complexity: O(n)  || 32.15% (20.2 MB)
 */
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> check;
        for (int& num : nums) {
            if (check.count(num)) return true;
            check.insert(num);
        }
        return false;
    }
};
/*
 * Approach: sort
 * Time complexity: O(n + nlogn)   || 6.02% (124 ms)
 * Space complexity: O(1)  || 56.76% (15.8 MB)
 */
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] == nums[i-1]) return true;
        }
        return false;
    }
};
/*
 * Approach: set - 1 line
 * Time complexity: O(n)   || 62.74% (64 ms)
 * Space complexity: O(n)  || 5.01% (22.7 MB)
 * Note: we don't need to check if element exists before but check size
 */
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        return nums.size() > set<int>(nums.begin(), nums.end()).size();
    }
};
// 72.39% (60 ms) + 35.56% (20.1 MB)
// Note that set's insert will spend a lot of time, but unordered_set will not.
// for expanding reserve space or not
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> dup;
        for (int i = 1; i <= nums.size(); i++) {
            dup.insert(nums[i-1]);
            if (dup.size() < i) return true;
        }
        return false;
    }
};