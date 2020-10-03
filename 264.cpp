/*
 * Approach: dp
 * Time complexity: O(n)   || 38.89% (28 ms)
 * Space complexity: O(n)  || 74.51% (7.6 MB)
 * Note: maintain 3 pointers, which points to the num that has not been multiplied by next '2', '3' and '5'
 */
class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> res(n, 1);
        int p[3] = {0};
        for (int i = 1; i < n; i++) {
            res[i] = min({res[p[0]] * 2, res[p[1]] * 3, res[p[2]] * 5});
            if (res[i] == res[p[0]] * 2) p[0]++;
            if (res[i] == res[p[1]] * 3) p[1]++;
            if (res[i] == res[p[2]] * 5) p[2]++;
        }
        return res[n-1];
    }
};
/*
 * Approach: optimize-ver
 * Time complexity: O(n)   || 69.32% (12 ms)
 * Space complexity: O(n)  || 63.77% (7.8 MB)
 */
class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> res(n, 1);
        int p[3] = {0};
        int tempV[3] = {2, 3, 5};
        for (int i = 1; i < n; i++) {
            res[i] = min(tempV[0], min(tempV[1], tempV[2]));
            while (tempV[0] <= res[i]) tempV[0] = 2 * res[++p[0]];
            while (tempV[1] <= res[i]) tempV[1] = 3 * res[++p[1]];
            while (tempV[2] <= res[i]) tempV[2] = 5 * res[++p[2]];
        }
        return res[n-1];
    }
};
/*
 * Approach: static (for multi-call, we can use the result calculated before)
 * Time complexity: O(n)   || 97.42% (4 ms)
 * Space complexity: O(n)  || 87.90% (6.1 MB)
 */
class Solution {
public:
    int nthUglyNumber(int n) {
        static vector<int> res{1};
        static int p[3] = {0};
        static int tempV[3] = {2, 3, 5};
        for (int i = res.size(); i < n; i++) {
            while (tempV[0] <= res[i-1]) tempV[0] = 2 * res[++p[0]];
            while (tempV[1] <= res[i-1]) tempV[1] = 3 * res[++p[1]];
            while (tempV[2] <= res[i-1]) tempV[2] = 5 * res[++p[2]];
            res.push_back(min(tempV[0], min(tempV[1], tempV[2])));
        }
        return res[n-1];
    }
};