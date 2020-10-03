/*
 * Approach: hashmap
 * Time complexity: O(n)   || 48.00% (48 ms)
 * Space complexity: O(n)  || 6.06% (19.9 MB)
 */
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> cnt;
        for (int num : nums) {
            if (++cnt[num] > nums.size() / 2) return num;
        }
        return nums[0];
    }
};
/*
 * Approach: partial sort
 * Time complexity: O(nlogn)   || 63.02% (44 ms)
 * Space complexity: O(1)  || 6.06% (19.8 MB)
 * Note: nth_element just sort for n-th element, here we just need to fix sort element at nums.size() / 2
 */
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size() / 2;
        nth_element(nums.begin(), nums.begin() + n, nums.end());
        return nums[n];
    }
};
/*
 * Approach: bit-manipulation
 * Time complexity: O(n)   || 19.75% (60 ms)
 * Space complexity: O(1)  || 6.06% (19.7 MB)
 * Note: use a bit-mask to get every bit in every num, just store the majority bit and combine them
 * Note: if the majority num does not contain a bit, then that bit can not be the majority bit
 */
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int majority = 0;
        for (unsigned int i = 0, mask = 1; ; i++, mask <<= 1) {
            int cnt = 0;
            for (int num : nums) {
                if (num & mask) cnt++;
            }
            if (cnt > nums.size() / 2) majority |= mask;
            // break before mask outreaches 32 bits(INT maximum bit)
            if (i == 31) break;
        }
        return majority;
    }
};
// use bitset is also ok
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int cnt[32] = {0};
        int n = nums.size() / 2;
        for (int num : nums) {
            bitset<32> bits(num);
            for (int i = 0; i < 32; i++) cnt[i] += bits[i];
        }
        bitset<32> majority;
        for (int i = 0; i < 32; i++) majority[i] = cnt[i] > n;
        return static_cast<int>(majority.to_ulong());
    }
};
/*
 * Approach: divide-and-conquer
 * Time complexity: O(n)   || 48.00% (48 ms)
 * Space complexity: O(logn)  || 6.06% (19.9 MB)
 * Note: T(n) = 2T(n/2) + 2n = ... = nT(1) + 4n - 4 = 5n - 4 = O(n)
 */
class Solution {
private:
    int majority(vector<int>& nums, int l, int r) {
        if (l == r) return nums[l];
        int m = (l + r) >> 1, lm = majority(nums, l, m), rm = majority(nums, m + 1, r);
        if (lm == rm) return lm;
        return count(nums.begin() + l, nums.begin() + r + 1, lm) > count(nums.begin() + l, nums.begin() + r + 1, rm) ? lm : rm;
    }
public:
    int majorityElement(vector<int>& nums) {
        return majority(nums, 0, nums.size() - 1);
    }
};
// time cost reduce to 75.71% (40ms), for T(n) = 2T(n/2) + n = 2n - 2
class Solution {
private:
    int my_count(vector<int>& nums, int l, int& r, int& lm, int& rm) {
        int lmcnt = 0, rmcnt = 0;
        while (l <= r) {
            if (nums[l] == lm) lmcnt++;
            else if (nums[l] == rm) rmcnt++;
            l++;
        }
        return lmcnt > rmcnt ? lm : rm;
    }
    int majority(vector<int>& nums, int l, int r) {
        if (l == r) return nums[l];
        int m = (l + r) >> 1, lm = majority(nums, l, m), rm = majority(nums, m + 1, r);
        if (lm == rm) return lm;
        return my_count(nums, l, r, lm, rm);
    }
public:
    int majorityElement(vector<int>& nums) {
        return majority(nums, 0, nums.size() - 1);
    }
};
/*
 * Approach: random
 * Time complexity: O(n^2)   || 63.21% (44 ms)
 * Space complexity: O(1)  || 6.06% (19.9 MB)
 * Note: 50% to select the majority and take O(n) time cost
 */
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        srand(unsigned(time(NULL)));
        while (1) {
            int select = nums[rand() % n], cnt = 0;
            for (int num : nums) if (num == select) cnt++;
            if (cnt > n / 2) return select;
        }
        return nums[0];
    }
};
/*
 * Approach: Moore voting (hard to think out)
 * Time complexity: O(n)   || 63.21% (44 ms)
 * Space complexity: O(1)  || 6.06% (19.7 MB)
 * Note: due to the majority amount > size / 2, then we can use two different numbers 'kill' each other
 * Note: Finally at least one majority will survive
 */
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int cnt = 0, majority;
        for (int num : nums) {
            if (!cnt) majority = num;
            cnt += num == majority ? 1 : -1;
        }
        return majority;
    }
};