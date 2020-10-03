/*
 * Approach: unorder_set (hash)
 * Time complexity: O(n)   || 60.25% (16 ms)
 * Space complexity: O(n)  || 5.77% (11.1 MB)
 * Note: only consider the increase of smallest consecutive number
 */
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> record;
        for (int num : nums) record.insert(num);
        int ret = 0, cur;
        for (int num : record) {
            if (record.count(num - 1) == 0) { // smallest
                cur = 1;
                while (record.count(num + 1)) {
                    num++;
                    cur++;
                }
                ret = cur > ret ? cur : ret;
            }
        }
        return ret;
    }
};
/*
 * Approach: unorder_map (hash)
 * Time complexity: O(n)   || 37.76% (20 ms)
 * Space complexity: O(n)  || 5.77% (11.4 MB)
 */
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int, int> record;
        int ret = 0, sum;
        for (int num : nums) {
            if (record[num] == 0) {
                sum = record[num - 1] + record[num + 1] + 1;
                ret = max(ret, sum);
                record[num] = sum;
                record[num - record[num - 1]] = sum;
                record[num + record[num + 1]] = sum;
            }
        }
        return ret;
    }
};
/*
 * Approach: Union Find
 * Time complexity: O(n)   || 37.76% (20 ms)
 * Space complexity: O(n)  || 5.77% (11.2 MB)
 * Note: UF class is defined in `Algorithm.cpp`
 */
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        UF uf = UF(nums.size());
        unordered_map<int, int> num2index;
        for (int i = 0; i < nums.size(); i++) {
            if (num2index.count(nums[i])) continue;
            if (num2index.count(nums[i] - 1)) uf.union(i, num2index[nums[i] - 1])
            if (num2index.count(nums[i] + 1)) uf.union(i, num2index[nums[i] + 1])
            num2index[nums[i]] = i;
        }
        return uf.getLargestUnion();
    }
};
UF::getLargestUnion() {
    int maxSize = 0;
    for (int i = 0; i < size.size(); i++) {
        if (parent[i] == i && size[i] > maxSize) maxSize = size[i];
    }
    return maxSize;
}