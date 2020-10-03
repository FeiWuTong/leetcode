/*
 * Approach: recursive (BFS)
 * Time complexity: O(n)   || 98.87% (4 ms)
 * Space complexity: O(n)  || 92.31% (19.2 MB)
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
    int depth = 0;
    void recursive(TreeNode* root, int i) {
        if (root) {
            i++;
            depth = max(depth, i);
            recursive(root->left, i), recursive(root->right, i);
        }
    }
public:
    int maxDepth(TreeNode* root) {
        recursive(root, 0);
        return depth;
    }
};
/*
 * Approach: DFS
 * Time complexity: O(n)   || 88.90% (8 ms)
 * Space complexity: O(n)  || 95.60% (19.2 MB)
 */
class Solution {
public:
    int maxDepth(TreeNode* root) {
        return root == NULL ? 0 : max(maxDepth(root->left), maxDepth(root->right)) + 1;
    }
};