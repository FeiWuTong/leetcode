/*
 * Approach: Recursive (DFS) (in-order)
 * Time complexity: O(n)   || 72.85% (28 ms)
 * Space complexity: O(n)  || 92.75% (24 MB)
 * Note: O(h) runtime take place in modifying the BST node's structure, with a new variable cnt to record its position
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
    int ret, cnt;
    // in-order
    void dfs(TreeNode* root) {
        if (root) {
            dfs(root->left);
            if (cnt <= 0) return;
            cnt--;
            if (cnt == 0) {
                ret = root->val;
                return;
            }
            dfs(root->right);
        }
    }
public:
    int kthSmallest(TreeNode* root, int k) {
        cnt = k;
        dfs(root);
        return ret;
    }
};
/*
 * Approach: binary-search (DFS)
 * Time complexity: O(n^2)   || 52.94% (32 ms)
 * Space complexity: O(n)  || 37.22% (24.3 MB)
 */
class Solution {
private:
    int count(TreeNode* root) {
        return root ? 1 + count(root->left) + count(root->right) : 0;
    }
public:
    int kthSmallest(TreeNode* root, int k) {
        int cnt = count(root->left);
        return k == cnt + 1 ? root->val : (k <= cnt ? kthSmallest(root->left, k) : kthSmallest(root->right, k - 1 - cnt));
    }
};