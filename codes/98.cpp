/*
 * Approach: DFS (inorder traversal / stack)
 * Time complexity: O(n)   || 53.81%
 * Space complexity: O(n)  || 5.21%
 * Note: pointer `pre` means current inorder root
 * Note: and `root` means 1. right subtree leftmost node. 2. parent of `pre` if `pre` has no right child
 * Note: Indeed, `root` is currently found leftmost node, and `pre` is last found's leftmost node
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
    bool isValidBST(TreeNode* root) {
        if (root == NULL) return true;
        stack<TreeNode*> st;
        TreeNode *pre = NULL;
        while (root != NULL || !st.empty()) {
            while (root != NULL) {
                st.push(root);
                root = root->left;
            }
            root = st.top();
            st.pop();
            if (pre != NULL && pre->val >= root->val) return false;
            pre = root;
            root = root->right;
        }
        return true;
    }
};
/*
 * Approach: recursive
 * Time complexity: O(n)   || 19.11%
 * Space complexity: O(n)  || 5.21%
 */
class Solution {
private:
    bool recursive(TreeNode* root, TreeNode* min_node, TreeNode* max_node) {
        if (root == NULL) return true;
        if (min_node && root->val <= min_node->val || max_node && root->val >= max_node->val) return false;
        return recursive(root->left, min_node, root) && recursive(root->right, root, max_node);
    }
public:
    bool isValidBST(TreeNode* root) {
        return recursive(root, NULL, NULL);
    }
};
/*
 * Approach: inorder-traverse (DFS / #94 same)
 * Time complexity: O(n)   || 53.81%
 * Space complexity: O(n)  || 97.92%
 */
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        if (root == NULL) return true;
        vector<int> ret;
        stack<TreeNode*> st;
        TreeNode *cur;
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
        for (int i = 1; i < ret.size(); i++) {
            if (ret[i-1] >= ret[i]) return false;
        }
        return true;
    }
};
// or
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
    bool isValidBST(TreeNode* root) {
        vector<int> ret;
        recursive(ret, root);
        for (int i = 1; i < ret.size(); i++) {
            if (ret[i-1] >= ret[i]) return false;
        }
        return true;
    }
};