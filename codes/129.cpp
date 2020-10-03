/*
 * Approach: Recursive (DFS)
 * Time complexity: O(n)   || 13.57% (8 ms)
 * Space complexity: O(n)  || 80.77% (12.4 MB)
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
    void recursive(int& sum, int& cur, TreeNode* root) {
        if (root && !root->left && !root->right) {
            sum += cur * 10 + root->val;
        } else {
            if (root->left) {
                cur = cur * 10 + root->val;
                recursive(sum, cur, root->left);
                cur = (cur - root->val) / 10;
            }
            if (root->right) {
                cur = cur * 10 + root->val;
                recursive(sum, cur, root->right);
                cur = (cur - root->val) / 10;
            }
        }
    }
public:
    int sumNumbers(TreeNode* root) {
        int sum = 0, cur = 0;
        if (root) recursive(sum, cur, root);
        return sum;
    }
};