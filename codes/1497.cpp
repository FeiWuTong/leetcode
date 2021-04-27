/*
 * Approach: Recursive (DFS)
 * Time complexity: O(n + k)   || 88.66% (256 ms)
 * Space complexity: O(k)  || 77.75% (61.6 MB)
 * Note: some edge cases, negative / i == 0 / i == k - i
 */
class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        int *remainder = (int *)malloc(sizeof(int) * k);
        memset(remainder, 0, sizeof(int) * k);
        for (int i = 0; i < arr.size(); i++) remainder[((arr[i] % k) + k) % k]++;
        for (int i = 0; i <= k / 2; i++) {
            if (i == 0 || i == k - i) {
                if (remainder[i] & 1) return false;
            } else {
                if (remainder[i] != remainder[k-i]) return false;
            }
        }
        return true;
    }
};