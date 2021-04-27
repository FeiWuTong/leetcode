/*
 * Approach: DP
 * Time complexity: -   || 77.12% (28 ms)
 * Space complexity: O(1) extra  || 77.78% (14.3 MB)
 * Note: memory-leek and clone operation
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
private:
    TreeNode* clone(TreeNode* root) {
        if (root == NULL) return NULL;
        TreeNode *newroot = new TreeNode(root->val);
        newroot->left = clone(root->left);
        newroot->right = clone(root->right);
        return newroot;
    }
public:
    vector<TreeNode*> generateTrees(int n) {
        vector<TreeNode*> ret(1, NULL);
        vector<TreeNode*> pre;
        if (n == 0) return pre;
        for (int i = 1; i <= n; i++) {
            for (TreeNode* root : ret) {
                // new root
                TreeNode *cur = new TreeNode(i);
                TreeNode *newroot = clone(root);
                cur->left = newroot;
                pre.push_back(cur);
                // insert right subtree to old tree
                TreeNode *pos = root;
                while (pos != NULL) {
                    TreeNode *new_subtree = new TreeNode(i);
                    new_subtree->left = pos->right;
                    pos->right = new_subtree;
                    pre.push_back(clone(root));
                    // recover
                    pos->right = new_subtree->left;
                    delete new_subtree;
                    new_subtree = NULL;
                    // go on
                    pos = pos->right;
                }
            }
            swap(ret, pre);
            pre.clear();
        }
        return ret;
    }
};
/*
 * Approach: recursive (similar to dp)
 * Time complexity: -   || 35.58% (36 ms)
 * Space complexity: -  || 41.67% (17.5 MB)
 */
class Solution {
private:
    vector<TreeNode*> recursive(int start, int end) {
        vector<TreeNode*> root;
        if (start > end) {
            root.push_back(NULL);
        };
        vector<TreeNode*> left;
        vector<TreeNode*> right;
        for (int i = start; i <= end; i++) {
            left = recursive(start, i - 1);
            right = recursive(i + 1, end);
            for (TreeNode *left_subtree : left) {
                for (TreeNode *right_subtree : right) {
                    TreeNode *cur_root = new TreeNode(i);
                    cur_root->left = left_subtree;
                    cur_root->right = right_subtree;
                    root.push_back(cur_root);
                }
            }
        }
        return root;
    }
public:
    vector<TreeNode*> generateTrees(int n) {
        if (n == 0) return vector<TreeNode*>();
        return recursive(1, n);
    }
};