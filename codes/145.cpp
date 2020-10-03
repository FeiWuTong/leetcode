/*
 * Approach: Recursive (DFS)
 * Time complexity: O(n)   || 32.80% (8 ms)
 * Space complexity: O(n)  || 100.00% (8.8 MB)
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private:
    vector<int> ret;
    void recursive(TreeNode* root) {
        if (root == NULL) return;
        recursive(root->left);
        recursive(root->right);
        ret.push_back(root->val);
    }
public:
    vector<int> postorderTraversal(TreeNode* root) {
        recursive(root);
        return ret;
    }
};
/*
 * Approach: stack
 * Time complexity: O(n)   || 32.80% (8 ms)
 * Space complexity: O(n)  || 100.00% (8.3 MB)
 */
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ret;
        stack<TreeNode*> todo;
        TreeNode *last = NULL;
        while (root || !todo.empty()) {
            if (root) {
                todo.push(root);
                root = root->left;
            } else {
                TreeNode *cur = todo.top();
                if (cur->right && cur->right != last) {
                    root = cur->right;
                } else {
                    todo.pop();
                    ret.push_back(cur->val);
                    last = cur;
                }
            }
        }
        return ret;
    }
};
/*
 * Approach: morris traverse
 * Time complexity: O(n)   || 100.00% (0 ms)
 * Space complexity: O(1)  || 100.00% (8.5 MB)
 */
class Solution {
private:
    vector<int> ret;
    void reverse(TreeNode* from, TreeNode* to) {
        if (from == to) return;
        TreeNode *x = from, *y = from->right, *z;
        while (x != to) {
            z = y->right;
            y->right = x;
            x = y;
            y = z;
        }
    }
    void reverseDo(TreeNode* from, TreeNode* to) {
        reverse(from, to);
        TreeNode *p = to;
        while (true) {
            ret.push_back(p->val);
            if (p == from) break;
            p = p->right;
        }
        reverse(to, from);
    }
public:
    vector<int> postorderTraversal(TreeNode* root) {
        TreeNode *dummy = new TreeNode(0);
        dummy->left = root;
        root = dummy;
        while (root) {
            if (root->left) {
                TreeNode *pre = root->left;
                while (pre->right && pre->right != root) pre = pre->right;
                if (pre->right == NULL) {
                    pre->right = root;
                    root = root->left;
                } else {
                    reverseDo(root->left, pre);
                    pre->right = NULL;
                    root = root->right;
                }
            } else {
                root = root->right;
            }
        }
        return ret;
    }
};