/*
 * Approach: Recursive (DFS)
 * Time complexity: O(n)   || 91.79% (40 ms)
 * Space complexity: O(n)  || 91.45% (11 MB)
 */
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
private:
    void DFS(vector<int>& ret, Node* root) {
        if (root) {
            ret.push_back(root->val);
            for (int i = 0; i < root->children.size(); i++)
                DFS(ret, root->children[i]);
        }
    }
public:
    vector<int> preorder(Node* root) {
        vector<int> ret;
        DFS(ret, root);
        return ret;
    }
};
/*
 * Approach: iteratively (stack)
 * Time complexity: O(n)   || 98.59% (36 ms)
 * Space complexity: O(n)  || 80.34% (11.1 MB)
 */
class Solution {
public:
    vector<int> preorder(Node* root) {
        vector<int> ret;
        stack<Node*> s;
        if (root) s.push(root);
        while (s.size()) {
            root = s.top();
            s.pop();
            ret.push_back(root->val);
            for (int i = root->children.size() - 1; i >= 0; i--)
                s.push(root->children[i]);
         }
        return ret;
    }
};