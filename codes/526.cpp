/*
 * Approach: backtracking
 * Time complexity: -   || 94.52% (12 ms)
 * Space complexity: -  || 64.24% (6 MB)
 */
class Solution {
private:
    int counts(vector<int>& arr, int n) {
        if (n <= 0) return 1;
        int ret = 0;
        for (int i = 0; i < n; i++) {
            if (arr[i] % n == 0 || n % arr[i] == 0) {
                swap(arr[i], arr[n-1]);
                ret += counts(arr, n - 1);
                swap(arr[n-1], arr[i]);
            }
        }
        return ret;
    }
public:
    int countArrangement(int N) {
        vector<int> arr(N);
        for (int i = 0; i < N; i++) arr[i] = i + 1;
        return counts(arr, N);
    }
};