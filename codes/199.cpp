/*
 * Approach: BFS (queue)
 * Time complexity: O(n)   || 100.00% (0 ms)
 * Space complexity: O(n)  || 5.41% (11.7 MB)
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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ret;
        if (!root) return ret;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            int cur = q.size();
            ret.push_back(q.front()->val);
            while (cur--) {
                TreeNode *node = q.front();
                q.pop();
                if (node->right) q.push(node->right);
                if (node->left) q.push(node->left);
            }
        }
        return ret;
    }
};
/*
 * Approach: DFS (recursive, preorder-like)
 * Time complexity: O(n)   || 71.29% (4 ms)
 * Space complexity: O(n)  || 5.41% (11.8 MB)
 */
class Solution {
private:
    vector<int> ret;
    void recursive(TreeNode* root, int level) {
        if (!root) return;
        if (ret.size() < level) ret.push_back(root->val);
        recursive(root->right, level + 1);
        recursive(root->left, level + 1);
    }
public:
    vector<int> rightSideView(TreeNode* root) {
        recursive(root, 1);
        return ret;
    }
};