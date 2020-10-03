/*
 * Approach: Recursive (DFS)
 * Time complexity: O(n)   || 19.59% (20 ms)
 * Space complexity: O(n)  || 8.48% (22 MB)
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
    int depthRecursive(TreeNode* root, bool &flag) {
        if (flag || root == NULL) return 0;
        else {
            int lh = depthRecursive(root->left, flag);
            int rh = depthRecursive(root->right, flag);
            if (max(lh, rh) - min(lh, rh) > 1) flag = true;
            return max(lh, rh) + 1;
        }
    }
public:
    bool isBalanced(TreeNode* root) {
        bool flag = false;
        depthRecursive(root, flag);
        return flag == false;
    }
};
/*
 * Approach: Recursive (DFS) (alter-ver)
 * Time complexity: O(n)   || 81.49% (12 ms)
 * Space complexity: O(n)  || 8.48% (21.8 MB)
 */
class Solution {
private:
    int depthRecursive(TreeNode* root) {
        if (root == NULL) return 0;
        int lh = depthRecursive(root->left);
        if (lh == -1) return -1;
        int rh = depthRecursive(root->right);
        if (rh == -1) return -1;
        if (abs(lh - rh) > 1) return -1;
        return max(lh, rh) + 1;
    }
public:
    bool isBalanced(TreeNode* root) {
        return depthRecursive(root) != -1;
    }
};