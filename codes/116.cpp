/*
 * Approach: iterative (BFS)
 * Time complexity: O(n)   || 94.90% (20 ms)
 * Space complexity: O(n)  || 100.00% (16.8 MB)
 * Note: utilize the `next` pointer
 */
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/
class Solution {
public:
    Node* connect(Node* root) {
        if (root) {
            Node *start = root, *cur;
            while (start->left) {
                cur = start;
                while (cur) {
                    cur->left->next = cur->right;
                    if (cur->next) cur->right->next = cur->next->left;
                    cur = cur->next;
                }
                start = start->left;
            }
        }
        return root;
    }
};
/*
 * Approach: recursive (DFS)
 * Time complexity: O(n)   || 55.47% (28 ms)
 * Space complexity: O(n)  || 100.00% (16.8 MB)
 */
class Solution {
public:
    Node* connect(Node* root) {
        if (root && root->left) {
            root->left->next = root->right;
            if (root->next) root->right->next = root->next->left;
            connect(root->left);
            connect(root->right);
        }
        return root;
    }
};