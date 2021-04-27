/*
 * Approach: regularity (mathematic method)
 * Time complexity: O(2^n)   || 100.00% (0 ms)
 * Space complexity: O(2^n)  || 100.00% (6.5 MB)
 * Note: if we have a s(n-1), then every num in s(n) - s(n-1) will be 2^(n-1)+2^(n-2) bigger than num in s(n-1)
 * Note: when the num out of range, then subtract 2^(n-1)
 * Note: why? Because the last num in s(n-1) would be 2^(n-2), then the next (faked first) num in s(n) would be 2^(n-1)+2^(n-2), which plus 2^(n-1)
 * Note: compare to the real first num 0 we can get the gap between them
 * Note: we can get a lot of remain `0` bit in that num
 * Note: then it evolves samely as s(n-2), so has the same gap
 * Note: when the num out of range, the subtraction is to continue the evolution
 * Note: which means the num after finishing s(n-2) should plus 2^(n-2) to enter s(n-1)
 * Note: but `11` the highest 2-bits will be `100`, so in order to cut off the new highest bit, we should take subtraction (-2^(n-1)) to make 2-bits become `10`
 * Note: or in other words, `11` left-shift 1 bit to be `10` to keep evolving s(n-1)
 */
class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> ret(1, 0);
        for (int i = 0; i < n; i++) {
            int s = ret.size();
            for (int j = 0; j < s; j++) {
                if (j < (s + 1) / 2) ret.push_back(ret[j] + ret[s-1] + (1 << i));
                else ret.push_back(ret[j] + ret[s-1]);
            }
        }
        return ret;
    }
};
/*
 * Approach: symmetric (whether left to right or right to left is ok)
 * Time complexity: O(2^n)   || 70.13% (4 ms)
 * Space complexity: O(2^n)  || 100.00% (6.5 MB)
 * Note: same as before, we utilize s(n-1) for s(n) generation
 * Note: since s(n-1) is symmetric, then s(n) can be s(n-1) | ^s(n-1) + 2^(n-1)
 * Note: where ^s(n-1) is the reverse of s(n-1), that is also the gray code
 */
class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> ret(1, 0);
        for (int i = 0; i < n; i++) {
            int s = ret.size() - 1;
            for (int j = s; j >= 0; j--) {
                ret.push_back(ret[j] + (1 << i));
            }
        }
        return ret;
    }
};
/*
 * Approach: increase natural and xor to be gray code
 * Time complexity: O(2^n)   || 100.00% (0 ms)
 * Space complexity: O(2^n)  || 100.00% (6.3 MB)
 * Note: same as Approach 1, but more concise
 * Note: obviously, mathematic method is faster and space-saving
 */
class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> ret(1, 0);
        for (int i = 0; i < pow(2, n); i++) ret.push_back(i ^ (i >> 1));
        return ret;
    }
};
/*
 * Approach: backtracking
 * Time complexity: O(2^n)   || 70.13% (4 ms)
 * Space complexity: O(2^n)  || 100.00% (7 MB)
 */
class Solution {
private:
    void backtrack(vector<int>& ret, bitset<32>& bits, int n) {
        if (n == 0) ret.push_back(bits.to_ulong());
        else {
            backtrack(ret, bits, n - 1);
            bits.flip(n - 1);
            backtrack(ret, bits, n - 1);
        }
    }
public:
    vector<int> grayCode(int n) {
        vector<int> ret;
        bitset<32> bits(0);
        backtrack(ret, bits, n);
        return ret;
    }
};