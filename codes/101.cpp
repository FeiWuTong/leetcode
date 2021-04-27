/*
 * Approach: recursive (BFS)
 * Time complexity: O(n)   || 31.11% (8 ms)
 * Space complexity: O(n)  || 8.48% (16.3 MB)
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
    bool judge(TreeNode* leftroot, TreeNode* rightroot) {
        if (leftroot == NULL || rightroot == NULL) return leftroot == rightroot;
        if (leftroot->val != rightroot->val) return false;
        return judge(leftroot->left, rightroot->right) && judge(leftroot->right, rightroot->left);
    }
public:
    bool isSymmetric(TreeNode* root) {
        return root == NULL || judge(root->left, root->right);
    }
};
/*
 * Approach: stack (DFS)
 * Time complexity: O(n)   || 31.11% (8 ms)
 * Space complexity: O(n)  || 8.48% (16.8 MB)
 */
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if (root == NULL) return true;
        stack<TreeNode*> st_l, st_r;
        TreeNode *left = root->left, *right = root->right;
        st_l.push(root), st_r.push(root);
        while (left || !st_l.empty() || right || !st_r.empty()) {
            if ((!left && right) || (left && !right)) return false;
            if (left && right) {
                if (left->val != right->val) return false;
                st_l.push(left);
                st_r.push(right);
                left = left->left;
                right = right->right;
            }
            else {
                left = st_l.top()->right;
                right = st_r.top()->left;
                st_l.pop();
                st_r.pop();
            }
        }
        return true;
    }
};