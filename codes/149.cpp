/*
 * Approach: hash + slope
 * Time complexity: O(n^2)   || 12.54% (116 ms)
 * Space complexity: -  || 14.29% (13.5 MB)
 * Note: exists duplicated points (OMG...)
 */
struct abi {
    int a, b, i;
    bool operator==(const abi &p) const {
        return p.a == a && p.b == b && p.i == i;
    }
};
namespace std {
    template <>
    struct hash<abi> {
        size_t operator () (const abi &f) const {
            return (std::hash<int>()(f.a) << 1) ^ std::hash<int>()(f.b) ^ std::hash<int>()(f.i);
        }
    };
}
class Solution {
private:
    abi getLine(vector<int>& p1, vector<int>& p2, int i) {
        abi line;
        line.a = p1[0] - p2[0];
        line.b = p1[1] - p2[1];
        line.i = i;
        return line;
    }
    bool isLine(vector<int>& p1, vector<int>& p2, abi line) {
        long long t1 = p1[1] - p2[1];
        t1 *= line.a;
        long long t2 = p1[0] - p2[0];
        t2 *= line.b;
        return t1 == t2;
    }
public:
    int maxPoints(vector<vector<int>>& points) {
        int n = points.size();
        if (n <= 2) return n;
        unordered_map<abi, vector<int>> table;
        abi line;
        // ignore duplicated points in first construct
        int ti = 1, maxP = 0;
        while (ti < n && points[ti][0] == points[0][0] && points[ti][1] == points[0][1]) ti++;
        if (ti == n) return n;
        line = getLine(points[0], points[ti], 0);
        for (int i = 0; i <= ti; i++, maxP++) table[line].push_back(i);

        for (int i = ti + 1; i < n; i++) {
            unordered_set<int> gen;
            for (auto it = table.begin(); it != table.end(); it++) {
                if (isLine(points[i], points[it->second[0]], it->first)) {
                    for (int p : it->second) gen.insert(p);
                    it->second.push_back(i);
                    maxP = max(maxP, int(it->second.size()));
                }
            }
            for (int j = 0; j < i; j++) {
                if (gen.count(j) == 0) {
                    line = getLine(points[i], points[j], i);
                    if (table.count(line) == 0) table[line].push_back(i);
                    table[line].push_back(j);
                }
            }
        }
        return maxP;
    }
};
/*
 * Approach: similar but concise
 * Time complexity: -   || 35.49% (48 ms)
 * Space complexity: -  || 64.29% (10.1 MB)
 */
class Solution {
private:
    int gcd(int a, int b) {
        while (b) {
            a = a % b;
            swap(a, b);
        }
        return a;
    }
    struct myhash {
        size_t operator() (const pair<int, int>& p) const {
            return p.first ^ (p.second * 2);
        }
    };
public:
    int maxPoints(vector<vector<int>>& points) {
        int n = points.size(), ans = 0;
        pair<int, int> cur;
        for (int i = 0; i < n; i++) {
            unordered_map<pair<int, int>, int, myhash> counter;
            int dup = 1;
            for (int j = i + 1; j < n; j++) {
                if (points[j] == points[i]) {
                    dup++;
                } else {
                    int dx = points[j][0] - points[i][0], dy = points[j][1] - points[i][1], g = gcd(dx, dy);
                    cur.first = dx / g;
                    cur.second = dy / g;
                    counter[cur]++;
                }
            }
            if (i == 0) ans = max(ans, dup);
            for (auto& p : counter) {
                ans = max(ans, p.second + dup);
            }
        }
        return ans;
    }
};
/*
 * Approach: only use vector (judge line same as #1) (faster than hash)
 * Time complexity: -   || 54.03% (36 ms)
 * Space complexity: -  || 35.71% (11.9 MB)
 * Note: 0 ms accepted submission is wrong, e.g. use case '[[1,4],[1,1],[4,1],[5,3],[2,3],[3,2]]' to test
 * Note: So we need to supplement some details
 */
class Solution {
private:
    struct pt
    {
        vector<int> pos;
        int cnt;
        pt(vector<int> p) : pos(p), cnt(1) {}
    };
    struct line
    {
        /* reference point and slope represented by slopex and slopey*/
        vector<int> ref;
        int slopex, slopey, cnt;
        line(vector<int> p, int sx, int sy, int pcnt) : ref(p), slopex(sx), slopey(sy), cnt(pcnt) {}
    };
    bool isLine(pt& p, line& l) {
        long long dx = l.ref[0] - p.pos[0];
        long long dy = l.ref[1] - p.pos[1];
        if (dx * l.slopey == dy * l.slopex) return true;
        return false;
    }
public:
    int maxPoints(vector<vector<int>>& points) {
        int n = points.size(), maxP = 0;
        vector<pt> uniquePt;
        vector<line> lines;
        bool exist;
        // initiate uniquePt
        for(int i = 0; i < n; i++) {
            exist = false;
            for (auto& p : uniquePt) {
                if (points[i] == p.pos) {
                    p.cnt++;
                    exist = true;
                    break;
                }
            }
            if (!exist) uniquePt.push_back(pt(points[i]));
        }
        // check uniquePt's size
        n = uniquePt.size();
        if (n < 2) return n == 1 ? uniquePt[0].cnt : 0;
        // construct lines
        for (int i = 1; i < n; i++) {
            vector<line> on;
            for (auto& l : lines) {
                if (isLine(uniquePt[i], l)) {
                    l.cnt += uniquePt[i].cnt;
                    on.push_back(l);
                }
            }
            for (int j = 0; j < i; j++) {
                exist = false;
                for (auto& l : on) {
                    if (isLine(uniquePt[j], l)) {
                        exist = true;
                        break;
                    }
                }
                if (!exist) {
                    lines.push_back(line(uniquePt[i].pos, 
                    uniquePt[i].pos[0] - uniquePt[j].pos[0], 
                    uniquePt[i].pos[1] - uniquePt[j].pos[1], 
                    uniquePt[i].cnt + uniquePt[j].cnt));
                }
            }
        }
        // find the maximum line
        for (int i = 0; i < lines.size(); i++) maxP = max(maxP, lines[i].cnt);
        return maxP;
    }
};