/*
 * Approach: DP
 * Time complexity: test average O(n ^ 1/2)   || 92.41% (8 ms)
 * Space complexity: O(n)  || 77.59% (6.3 MB)
 */
class Solution {
public:
    int numSquares(int n) {
        if (n <= 0) return 0;
        static vector<int> dp({0});
        while (dp.size() <= n) {
            int m = dp.size(), cnt = INT_MAX;
            for (int i = 1; i * i <= m; i++) {
                cnt = min(cnt, dp[m - i * i] + 1);
            }
            dp.push_back(cnt);
        }
        return dp[n];
    }
};
/*
 * Approach: Math (Lagrange's Four Square theorem)
 * Time complexity: O(n ^ 1/2)   || 100.00% (0 ms)
 * Space complexity: O(1)  || 95.94% (5.9 MB)
 * Note: unable to think out this method when lack of the knowledge...
 * Note: every positive integer can be expressed as the sum of 4 sqaures numbers
 */
class Solution {
private:
    bool is_square(int n) {
        int sqrt_n = sqrt(n);
        return n == sqrt_n * sqrt_n;
    }
public:
    int numSquares(int n) {
        if (is_square(n)) return 1;
        // remove factor 4 (2 * 2)
        while ((n & 3) == 0) {
            n >>= 2;
        }
        // n % 8 == 7
        if ((n & 7) == 7) return 4;
        // check 2
        int sqrt_n = sqrt(n);
        for (int i = 1; i <= sqrt_n; i++) {
            if (is_square(n - i * i)) return 2;
        }
        // only choice 3
        return 3;
    }
};
/*
 * Approach: BFS
 * Time complexity: -   || 65.32% (200 ms)
 * Space complexity: -  || 7.57% (25.8 MB)
 * Note: Because the answer is no more than 4, we can use BFS...
 */
class Solution {
public:
    int numSquares(int n) {
        queue<int> q;
        q.push(0);
        // BFS check whether this node had been visited before
        unordered_set<int> visited;
        int depth = 0;
        while (!q.empty()) {
            int cur_size = q.size();
            depth++;
            while (cur_size--) {
                int cur = q.front();
                q.pop();
                for (int i = 1; i * i <= n - cur; i++) {
                    int next = cur + i * i;
                    if (next == n) return depth;
                    if (visited.count(next) == 0) {
                        q.push(next);
                        visited.insert(next);
                    }
                }
            }
        }
        return depth;
    }
};