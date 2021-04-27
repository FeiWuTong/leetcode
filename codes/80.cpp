/*
 * Approach: two pointers
 * Time complexity: O(n)   || 78.25%
 * Space complexity: O(1)  || 100.00%
 */
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() < 2) return nums.size();
        bool flag = false;
        int len = 1, pos = 0;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] == nums[pos]) {
                if (flag) {
                    int cur = i;
                    while (i < nums.size() && nums[i] == nums[cur]) i++;
                    if (i == nums.size()) break;
                    flag = false;
                }
                else flag = true;
            }
            else flag = false;
            nums[++pos] = nums[i];
            len++;
        }
        return len;
    }
};
/*
 * Approach: two pointers (clean verb)
 * Time complexity: O(n)   || 6.63%-78.25% (36ms, 20ms, 12ms)
 * Space complexity: O(1)  || 100.00%
 * Note: not equal(!=) is faster than bigger(>)
 */
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i = 0;
        for (int n : nums) {
            if (i < 2 || n > nums[i-2]) nums[i++] = n;
        }
        return i;
    }
};
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i = 0;
        for (int j = 0; j < nums.size(); j++) {
            if (j < 2 || nums[j] > nums[i-2]) nums[i++] = nums[j];
        }
        return i;
    }
};
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() < 2) return nums.size();
        int i = 2;
        for (int j = 2; j < nums.size(); j++) {
            if (nums[j] > nums[i-2]) nums[i++] = nums[j];
        }
        return i;
    }
};
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() < 2) return nums.size();
        int i = 2;
        for (int j = 2; j < nums.size(); j++) {
            if (nums[j] != nums[i-2]) nums[i++] = nums[j];
        }
        return i;
    }
};