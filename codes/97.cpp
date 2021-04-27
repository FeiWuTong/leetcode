/*
 * Approach: DP (2d array)
 * Time complexity: O(n^2)   || 100.00%
 * Space complexity: O(n^2)  || 100.00%
 */
class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        if (s3.size() != s1.size() + s2.size()) return false;
        bool dp[s1.size()+1][s2.size()+1]; // 0 represents empty string
        for (int i = 0; i <= s1.size(); i++) {
            for (int j = 0; j <= s2.size(); j++) {
                if (i == 0 && j == 0) dp[i][j] = true;
                else if (i == 0) dp[i][j] = dp[i][j-1] && s2[j-1] == s3[i+j-1];
                else if (j == 0) dp[i][j] = dp[i-1][j] && s1[i-1] == s3[i+j-1];
                else dp[i][j] = (dp[i-1][j] && s1[i-1] == s3[i+j-1]) || (dp[i][j-1] && s2[j-1] == s3[i+j-1]);
            }
        }
        return dp[s1.size()][s2.size()];
    }
};
/*
 * Approach: DP (1d array)
 * Time complexity: O(n^2)   || 100.00%
 * Space complexity: O(n^2)  || 100.00%
 * Note: dp[i][j-1] equals to in j's loop the last dp[i]
 */
class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        if (s3.size() != s1.size() + s2.size()) return false;
        bool dp[s1.size()+1];
        dp[0] = true;
        // because j is start from 1, so j = 0 needs calculation before loop
        for (int i = 1; i <= s1.size(); i++) {
            dp[i] = dp[i-1] && s1[i-1] == s3[i-1];
        }
        for (int j = 1; j <= s2.size(); j++) {
            dp[0] = dp[0] && s2[j-1] == s3[j-1];
            for (int i = 1; i <= s1.size(); i++) {
                dp[i] = (dp[i-1] && s1[i-1] == s3[i+j-1]) || (dp[i] && s2[j-1] == s3[i+j-1]);
            }
        }
        return dp[s1.size()];
    }
};
/*
 * Approach: BFS (good coding)
 * Time complexity: O(n^2)   || 72.49% (4 ms)
 * Space complexity: O(n^2)  || 100.00%
 * Note: construct a chessboard and use BFS to rightly reach bottom-right
 * Note: e.g. `aab` and `abc` to get `aaabcb` 
o--a--o--b--o--c--o
|     |     |     |
a     a     a     a
|     |     |     |
o--a--o--b--o--c--o
|     |     |     |
a     a     a     a
|     |     |     |
o--a--o--b--o--c--o
|     |     |     |
b     b     b     b
|     |     |     |
o--a--o--b--o--c--o
 */
struct MyPoint {
    int y, x; 
    bool operator==(const MyPoint &p) const {
        return p.y == y && p.x == x;
    }
};
namespace std {
    template <>
    struct hash<MyPoint> {
        size_t operator () (const MyPoint &f) const {
            return (std::hash<int>()(f.x) << 1) ^ std::hash<int>()(f.y);
        }
    };
}

class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        if (s1.size() + s2.size() != s3.size()) return false;

        queue<MyPoint> q;
        unordered_set<MyPoint> visited;
        int i = 0;

        q.push(MyPoint { 0, 0 });
        q.push(MyPoint { -1, -1 });
        while (!(1 == q.size() && -1 == q.front().x)) {
            auto p = q.front();
            q.pop();
            if (p.y == s1.size() && p.x == s2.size()) {
                return true;
            }
            if (-1 == p.y) {
                q.push(p);
                i++;
                continue;
            }
            if (visited.find(p) != visited.end()) { continue; }
            visited.insert(p);

            if (p.y < s1.size()) { // down
                if (s1[p.y] == s3[i]) { q.push(MyPoint { p.y + 1, p.x }); }
            }
            if (p.x < s2.size()) { // right 
                if (s2[p.x] == s3[i]) { q.push(MyPoint { p.y, p.x + 1 }); }
            }
        }
        return false;
    }
};