/*
 * Approach: iterative (BFS) (same as #116)
 * Time complexity: O(n)   || 85.60% (16 ms)
 * Space complexity: O(n)  || 100.00% (17.2 MB)
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
            Node *start = root, *cur, *last;
            while (start) {
                cur = start;
                start = NULL;
                while (cur) {
                    if (cur->left) {
                        if (cur->right) cur->left->next = cur->right, last = cur->right;
                        else last = cur->left;
                        if (!start) start = cur->left;
                    }
                    else {
                        if (!start) start = cur->right;
                        last = cur->right;
                    }
                    if (last) {
                        while (cur->next) {
                            if (cur->next->left) last->next = cur->next->left;
                            else if(cur->next->right) last->next = cur->next->right;
                            else {
                                cur = cur->next;
                                continue;
                            }
                            break;
                        }
                    }
                    cur = cur->next;
                }
            }
        }
        return root;
    }
};
/*
 * Approach: iterative (BFS) (1 loop concise !!!)
 * Time complexity: O(n)   || 85.60% (16 ms)
 * Space complexity: O(n)  || 100.00% (17.2 MB)
 * Note: use a dummy node to find out the leftmost node
 * Note: and one loop can traverse from left to right, then go down-level
 */
class Solution {
public:
    Node* connect(Node* root) {
        Node *dummyHead = new Node(0);
        Node *pre = dummyHead, *cur = root;
        while (cur) {
            if (cur->left) {
                pre->next = cur->left;
                pre = pre->next;
            }
            if (cur->right) {
                pre->next = cur->right;
                pre = pre->next;
            }
            cur = cur->next;
            if (cur == nullptr) { // go down to next level
                pre = dummyHead;
                cur = dummyHead->next;
                dummyHead->next = nullptr;
            } 
        }
        return root;
    }
};
/*
 * Approach: recursive (DFS)
 * Time complexity: O(n)   || 85.60% (16 ms)
 * Space complexity: O(n)  || 100.00% (17.5 MB)
 * Note: traverse right subtree at first (tricky)
 */
class Solution {
private:
    Node* fnext(Node* root) {
        if (root == NULL) return NULL;
        if (root->left) return root->left;
        if (root->right) return root->right;
        return fnext(root->next);
    }
public:
    Node* connect(Node* root) {
        if (root == NULL) return root;
        if (root->left) {
            if (root->right) root->left->next = root->right;
            else root->left->next = fnext(root->next);
        }
        if (root->right) root->right->next = fnext(root->next);
        connect(root->right);
        connect(root->left);
        return root;
    }
};