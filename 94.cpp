/*
 * Approach: recursive
 * Time complexity: O(n)   || 26.70% (4 ms)
 * Space complexity: O(n)  || 100.00% (7.1 MB)
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
    void recursive(vector<int>& ret, TreeNode* cur) {
        if (cur != NULL) {
            recursive(ret, cur->left);
            ret.push_back(cur->val);
            recursive(ret, cur->right);
        }
    }
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ret;
        recursive(ret, root);
        return ret;
    }
};
/*
 * Approach: iteratively (stack)
 * Time complexity: O(n)   || 100.00% (0 ms)
 * Space complexity: O(n)  || 100.00% (6.6 MB)
 */
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ret;
        stack<TreeNode*> st;
        TreeNode *cur;
        if (root == NULL) return ret;
        st.push(root);
        while (!st.empty()) {
            cur = st.top();
            if (cur->left == NULL) {
                st.pop();
                ret.push_back(cur->val);
                if (cur->right != NULL) st.push(cur->right);
            }
            else {
                st.push(cur->left);
                cur->left = NULL;
            }
        }
        return ret;
    }
};
/*
 * Approach: stack2 (not modify the tree)
 * Time complexity: O(n)   || 100.00% (0 ms)
 * Space complexity: O(n)  || 100.00% (6.6 MB)
 */
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ret;
        if (root == NULL) return ret;
        stack<TreeNode*> st;
        while (root != NULL || !st.empty()) {
            while (root != NULL) {
                st.push(root);
                root = root->left;
            }
            root = st.top();
            st.pop();
            ret.push_back(root->val);
            root = root->right;
        }
        return ret;
    }
};