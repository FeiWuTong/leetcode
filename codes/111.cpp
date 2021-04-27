/*
 * Approach: Recursive (DFS) (not the best)
 * Time complexity: O(n)   || 76.61% (12 ms)
 * Space complexity: O(n)  || 64.28% (19.9 MB)
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
    int minDepth(TreeNode* root) {
        if (root == NULL) return 0;
        if (root->left == NULL) return minDepth(root->right) + 1;
        if (root->right == NULL) return minDepth(root->left) + 1;
        return min(minDepth(root->left), minDepth(root->right)) + 1;
    }
};
/*
 * Approach: stack (BFS) (the best)
 * Time complexity: O(n)   || 97.15% (8 ms)
 * Space complexity: O(n)  || 64.28% (19.9 MB)
 */
class Solution {
public:
    int minDepth(TreeNode* root) {
        if (root == NULL) return 0;
        int ret = 1, s;
        queue<TreeNode*> q;
        TreeNode *cur;
        q.push(root);

        while (!q.empty()) {
            s = q.size();
            while (s--) {
                cur = q.front();
                q.pop();
                if (cur->left == NULL && cur->right == NULL) return ret;
                if (cur->left != NULL) q.push(cur->left);
                if (cur->right != NULL) q.push(cur->right);
            }
            ret++;
        }
        return ret;
    }
};