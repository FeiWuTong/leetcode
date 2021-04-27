/*
 * Approach: DFS (recursive)
 * Time complexity: -   || 85.44% (4 ms)
 * Space complexity: -  || 18.87% (14.4 MB)
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
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ret;
        if (root == NULL) return ret;
        for (string& s : binaryTreePaths(root->left)) {
            ret.push_back(to_string(root->val) + "->" + s);
        }
        for (string& s : binaryTreePaths(root->right)) {
            ret.push_back(to_string(root->val) + "->" + s);
        }
        return ret.size() ? ret : vector<string>{to_string(root->val)};
    }
};