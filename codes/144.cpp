/*
 * Approach: Recursive (DFS)
 * Time complexity: O(n)   || 100.00% (0 ms)
 * Space complexity: O(n)  || 100.00% (8.7 MB)
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
        ret.push_back(root->val);
        recursive(root->left);
        recursive(root->right);
    }
public:
    vector<int> preorderTraversal(TreeNode* root) {
        recursive(root);
        return ret;
    }
};
/*
 * Approach: iteratively (stack)
 * Time complexity: O(n)   || 29.29% (4 ms)
 * Space complexity: O(n)  || 100.00% (8.7 MB)
 */
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ret;
        stack<TreeNode*> todo;
        todo.push(root);
        while (!todo.empty()) {
            TreeNode *cur = todo.top();
            todo.pop();
            if (cur) {
                ret.push_back(cur->val);
                todo.push(cur->right);
                todo.push(cur->left);
            }
        }
        return ret;
    }
};