/*
 * Approach: DFS (like #105)
 * Time complexity: O(n)   || 20.20% - 97.86% (52 ms - 12 ms)
 * Space complexity: O(n)  || 11.11% (24.3 MB)
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
    unordered_map<int, int> table;
    void initTable(vector<int>& inorder) {
        for (int i = 0; i < inorder.size(); i++) { table.emplace(inorder[i], i); }
    }
    TreeNode* buildRecursive(vector<int>& inorder, vector<int>& postorder, int in_s, int in_e, int post_s, int post_e) {
        if (post_s >= post_e) { return NULL; }

        int pos = table[postorder[post_e - 1]];
        int rightsize = in_e - 1 - pos;
        /*
        auto pos = find(inorder.begin() + in_s, inorder.begin() + in_e, \
        postorder[post_e - 1]);
        int rightsize = inorder.begin() + in_e - 1 - pos;
        */

        TreeNode *root = new TreeNode(postorder[post_e - 1], \
        buildRecursive(inorder, postorder, in_s, in_e - 1 - rightsize, post_s, post_e - 1 - rightsize), \
        buildRecursive(inorder, postorder, in_e - rightsize, in_e, post_e - 1 - rightsize, post_e - 1));

        return root;
    }
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        initTable(inorder);
        return buildRecursive(inorder, postorder, 0, inorder.size(), 0, postorder.size());
    }
};