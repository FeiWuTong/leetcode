/*
 * Approach: Recursive (DFS) (elegant)
 * Time complexity: O(n)   || 5.17% (88 ms)
 * Space complexity: O(n)  || 6.06% (28.5 MB)
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
    int maxS;
    int recursive(TreeNode* root) {
        if (root == NULL) return 0;
        int left = max(0, recursive(root->left));
        int right = max(0, recursive(root->right));
        maxS = max(maxS, left + right + root->val);
        return max(left, right) + root->val;
    }
public:
    int maxPathSum(TreeNode* root) {
        if (root == NULL) return 0;
        maxS = root->val;
        recursive(root);
        return maxS;
    }
};
/*
 * Approach: same (faster alter)
 * Time complexity: O(n)   || 24.30% (44 ms)
 * Space complexity: O(n)  || 6.06% (27.8 MB)
 */
class Solution {
private:
    int maxS;
    int recursive(TreeNode* root, int &maxS) {
        if (root == NULL) return 0;
        int left = recursive(root->left, maxS);
        int right = recursive(root->right, maxS);
        if (left < 0) left = 0;
        if (right < 0) right = 0;
        maxS = maxS < left + right + root->val ? left + right + root->val : maxS;
        if (left > right) return root->val + left;
        else return root->val + right;
    }
public:
    int maxPathSum(TreeNode* root) {
        if (root == NULL) return 0;
        int maxS = root->val;
        recursive(root, maxS);
        return maxS;
    }
};