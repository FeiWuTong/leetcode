/*
 * Approach: stack (DFS)
 * Time complexity: O(n)   || 97.93% (4 ms)
 * Space complexity: O(n)  || 8.33% (12.4 MB)
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
    void flatten(TreeNode* root) {
        TreeNode *last = new TreeNode(0), *cur = root;
        stack<TreeNode*> st;
        while (cur || !st.empty()) {
            while (cur) {
                st.push(cur->right);
                last->left = NULL, last->right = cur;
                last = cur;
                cur = cur->left;
            }
            cur = st.top();
            st.pop();
        }
    }
};
/*
 * Approach: recursive
 * Time complexity: O(n)   || 97.93% (4 ms)
 * Space complexity: O(n)  || 8.33% (11.9 MB)
 */
class Solution {
private:
    TreeNode *last;
public:
    void flatten(TreeNode* root) {
        if (!root) return;
        if (!root->right && !root->left) {
            last = root;
            return;
        }
        if (root->left) {
            flatten(root->left);
            last->right = root->right;
            root->right = root->left;
            root->left = NULL;
        }
        flatten(root->right);
    }
};