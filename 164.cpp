/*
 * Approach: bucket-sort
 * Time complexity: O(n)   || 63.91% (12 ms)
 * Space complexity: O(n)  || 100.00% (9.3 MB)
 * Note: if there exists duplicate number, gap may be 0 which is unreasonable
 * Note: we only need to store max/min in bucket, for the elements between have no signification (less than gap)
 */
class Solution {
public:
    int maximumGap(vector<int>& nums) {
        int n = nums.size();
        if (n < 2) return 0;
        // O(n) get buckets' gap
        int maxN = nums[0], minN = nums[0];
        for (int i : nums) {
            if (i > maxN) maxN = i;
            else if (i < minN) minN = i;
        }
        int gap = max((maxN - minN) / (n - 1), 1);
        // m buckets
        int m = (maxN - minN) / gap + 1, k;
        vector<int> minB(m, INT_MAX);
        vector<int> maxB(m, INT_MIN);
        // O(n) bucket-sort
        for (int i : nums) {
            k = (i - minN) / gap;
            if (i < minB[k]) minB[k] = i;
            if (i > maxB[k]) maxB[k] = i;
        }
        // O(n) traverse all buckets' borders
        gap = maxB[0] - minB[0];
        for (int i = 0, j = i + 1; j < m; j++) {
            // for j >= 1, if bucket contain element, maxB[j] impossibly be INT_MIN
            if (maxB[j] != INT_MIN) {
                gap = max(gap, minB[j] - maxB[i]);
                i = j;
            }
        }
        return gap;
    }
};
/*
 * Approach: radix-sort (also a bucket-sort)
 * Time complexity: O(n)   || 34.03% (16 ms)
 * Space complexity: O(n)  || 100.00% (8.9 MB)
 * Note: #1 is half-sort, this is whole-sort, but positive number only
 */
class Solution {
public:
    int maximumGap(vector<int>& nums) {
        int n = nums.size();
        if (n < 2) return 0;
        // O(n) get max to be the loop's judge condition
        int maxN = nums[0];
        for (int i : nums) {
            if (i > maxN) maxN = i;
        }
        // n buckets
        int exp = 1;
        const int base = 10;
        int *aux = new int[n];
        // O(logbase(maxN) * n) bucket-sort
        while (maxN / exp > 0) {
            int count[base] = {0};
            // statis every bucket-count's elements' amount
            for (int num : nums) {
                count[(num / exp) % base]++;
            }
            // now count becomes index indicator
            for (int i = 1; i < base; i++) {
                count[i] += count[i-1];
            }
            // sort this round (this bit)
            for (int i = n - 1; i >= 0; i--) {
                aux[--count[(nums[i] / exp) % base]] = nums[i];
            }
            // return this round sort result to original nums
            for (int i = 0; i < n; i++) {
                nums[i] = aux[i];
            }
            exp *= base;
        }
        // O(n) traverse sort list
        int gap = 0;
        for (int i = 1; i < n; i++) {
            gap = max(gap, nums[i] - nums[i-1]);
        }
        return gap;
    }
};