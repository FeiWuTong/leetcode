/*
 * Approach: Recursive (DFS)
 * Time complexity: O(n)   || 41.33% (4 ms)
 * Space complexity: O(n)  || 52.78% (8.3 MB)
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
public:
    TreeNode* invertTree(TreeNode* root) {
        if (root) {
            root->left = invertTree(root->left);
            root->right = invertTree(root->right);
            swap(root->left, root->right);
        }
        return root;
    }
};
/*
 * Approach: queue (BFS)
 * Time complexity: O(n)   || 100.00% (0 ms)
 * Space complexity: O(n)  || 5.14% (8.8 MB)
 */
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        TreeNode* R = root;
        queue<TreeNode*> q;
        if (root) q.push(root);
        while (!q.empty()) {
            root = q.front();
            q.pop();
            swap(root->left, root->right);
            if (root->left) q.push(root->left);
            if (root->right) q.push(root->right);
        }
        return R;
    }
};