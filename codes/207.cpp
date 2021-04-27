/*
 * Approach: BFS (topological sort)
 * Time complexity: O(V+E)   || 86.18% (36 ms)
 * Space complexity: O(V+E)  || 71.06% (13.3 MB)
 * Note: Indeed it is checking directed graph's cycle problem
 * Note: In BFS, find a node with 0 indegree, and cut all the out-edge
 * Note: Finally if not all nodes is 0 indegree, then there must be a cycle in graph
 */
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses, vector<int>());
        vector<int> indegree(numCourses, 0);
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
        while (!q.empty()) {
            for (auto adj : graph[q.front()]) {
                if (--indegree[adj] == 0) q.push(adj);
            }
            q.pop(), numCourses--;
        }
        return numCourses == 0;
    }
};
/*
 * Approach: DFS (topological sort)
 * Time complexity: O(V+E)   || 74.20% (40 ms)
 * Space complexity: O(V+E)  || 50.91% (13.9 MB)
 */
class Solution {
private:
    bool recursive(vector<vector<int>>& g, vector<bool>& done, vector<bool>& visited, int i) {
        if (visited[i]) return false;
        if (done[i]) return true;
        done[i] = visited[i] = true;
        for (int v : g[i]) {
            if (!recursive(g, done, visited, v)) return false;
        }
        visited[i] = false;
        return true;
    }
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses, vector<int>());
        vector<bool> done(numCourses, false), visited(numCourses, false);
        // build graph
        for (auto& p : prerequisites) graph[p[1]].push_back(p[0]);
        // DFS
        for (int i = 0; i < numCourses; i++) {
            if (!done[i] && !recursive(graph, done, visited, i)) return false;
        }
        return true;
    }
};