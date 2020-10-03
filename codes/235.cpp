/*
 * Approach: Recursive
 * Time complexity: O(h)   || 73.24% (40 ms)
 * Space complexity: O(h)  || 72.31% (23.3 MB)
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (p->val < root->val && q->val > root->val || p->val > root->val && q->val < root->val) return root;
        if (root->val == p->val || root->val == q->val) return root;
        return root->val > p->val ? lowestCommonAncestor(root->left, p, q) : lowestCommonAncestor(root->right, p, q);
    }
};