/*
 * Approach: Recursive (DFS)
 * Time complexity: O(n)   || 91.90% (8 ms)
 * Space complexity: -  || 100.00% (8.9 MB)
 */
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
private:
    unordered_map<int, Node*> check;
public:
    Node* cloneGraph(Node* node) {
        if (node == NULL) return NULL;
        if (check.count(node->val) == 0) {
            check[node->val] = new Node(node->val);
            for (Node *adj : node->neighbors) {
                check[node->val]->neighbors.push_back(cloneGraph(adj));
            }
        }
        return check[node->val];
    }
};
/*
 * Approach: BFS
 * Time complexity: O(n)   || 53.07% (12 ms)
 * Space complexity: -  || 100.00% (8.6 MB)
 */
class Solution {
private:
    unordered_map<int, Node*> check;
public:
    Node* cloneGraph(Node* node) {
        if (node == NULL) return NULL;
        Node *copynode = new Node(node->val);
        check[node->val] = copynode;
        queue<Node*> q;
        q.push(node);
        while (!q.empty()) {
            Node *cur = q.front();
            q.pop();
            for (Node *adj : cur->neighbors) {
                if (check.find(adj->val) == check.end()) {
                    check[adj->val] = new Node(adj->val);
                    q.push(adj);
                }
                check[cur->val]->neighbors.push_back(check[adj->val]);
            }
        }
        return copynode;
    }
};