/*
 * Approach: sort
 * Time complexity: O(nlogn)   || 92.09% (4 ms)
 * Space complexity: O(1)  || 89.89% (8.6 MB)
 */
class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        sort(citations.begin(), citations.end());
        for (int i = 0; i < n; i++) {
            if (citations[i] >= n - i) return n - i;
        }
        return 0;
    }
};
/*
 * Approach: index table (bucket)
 * Time complexity: O(n)   || 92.09% (4 ms)
 * Space complexity: O(n)  || 9.75% (9 MB)
 * Note: refer to #1 method
 */
class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        vector<int> idt(n + 1, 0);
        for (int i = 0; i < n; i++) {
            if (citations[i] <= n) idt[citations[i]]++;
            else idt[n]++;
        }
        int sum = 0;
        for (int i = n; i >= 0; i--) {
            sum += idt[i];
            if (sum >= i) return i;
        }
        return 0;
    }
};