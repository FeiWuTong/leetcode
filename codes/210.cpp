/*
 * Approach: BFS (same as #207)
 * Time complexity: O(V+E)   || 71.66% (40 ms)
 * Space complexity: O(V+E)  || 67.72% (13.4 MB)
 */
class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses, vector<int>());
        vector<int> indegree(numCourses, 0), ret(numCourses);
        // build graph and count every node's indegree
        for (auto& p : prerequisites) {
            graph[p[1]].push_back(p[0]);
            indegree[p[0]]++;
        }
        // record 0-indegree node's label
        queue<int> q;
        for (int i = 0; i < numCourses; i++) {
            if (indegree[i] == 0) q.push(i);
        }
        // cut 0-indegree node's out-edge, and refresh 0-indegree queue
        int i = 0;
        while (!q.empty()) {
            for (auto adj : graph[q.front()]) {
                if (--indegree[adj] == 0) q.push(adj);
            }
            ret[i++] = q.front();
            q.pop(), numCourses--;
        }
        if (numCourses) return {};
        return ret;
    }
};
/*
 * Approach: DFS (same as #207)
 * Time complexity: O(V+E)   || 23.14% (60 ms)
 * Space complexity: O(V+E)  || 45.19% (14.2 MB)
 * Note: need to save node reversely
 */
class Solution {
private:
    vector<int> ret;
    int id;
    bool recursive(vector<vector<int>>& g, vector<bool>& done, vector<bool>& visited, int i) {
        if (visited[i]) return false;
        if (done[i]) return true;
        done[i] = visited[i] = true;
        for (int v : g[i]) {
            if (!recursive(g, done, visited, v)) return false;
        }
        ret[--id] = i;
        visited[i] = false;
        return true;
    }
public:
     vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses, vector<int>());
        vector<bool> done(numCourses, false), visited(numCourses, false);
        ret.resize(numCourses);
        id = numCourses;
        // build graph
        for (auto& p : prerequisites) graph[p[1]].push_back(p[0]);
        // DFS
        for (int i = 0; i < numCourses; i++) {
            if (!done[i] && !recursive(graph, done, visited, i)) return {};
        }
        return ret;
    }
};