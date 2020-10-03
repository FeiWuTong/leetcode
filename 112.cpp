/*
 * Approach: recursive (DFS)
 * Time complexity: O(n)   || 38.42% (16 ms)
 * Space complexity: O(n)  || 6.25% (21.4 MB)
 * Note: Negative sum is also valid
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
    bool hasPathSum(TreeNode* root, int sum) {
        if (root == NULL) return false;
        if (root->val == sum && root->left == NULL && root->right == NULL) return true;
        return hasPathSum(root->left, sum - root->val) || hasPathSum(root->right, sum - root->val);
    }
};
/*
 * Approach: Recursive (BFS)
 * Time complexity: O(n)   || 38.42% (16 ms)
 * Space complexity: O(n)  || 6.25% (21.5 MB)
 */
class Solution {
public:
    bool hasPathSum(TreeNode* root, int sum) {
        if (root == NULL) return false;
        queue<pair<TreeNode*, int>> q;
        int s;
        pair<TreeNode*, int> cur;
        q.push(make_pair(root, root->val));

        while (!q.empty()) {
            s = q.size();
            while (s--) {
                cur = q.front();
                q.pop();
                if (cur.first->left == NULL && cur.first->right == NULL && cur.second == sum) return true;
                if (cur.first->left != NULL) { q.push(make_pair(cur.first->left, cur.second + cur.first->left->val)); }
                if (cur.first->right != NULL) { q.push(make_pair(cur.first->right, cur.second + cur.first->right->val)); }
            }
        }
        return false;
    }
};
/*
 * Approach: recursive (DFS) (use reference)
 * Time complexity: O(n)   || 71.86% (12 ms)
 * Space complexity: O(n)  || 6.25% (21.4 MB)
 */
class Solution {
private:
    bool recursive(TreeNode* root, int &sum) {
        if (root == NULL) return false;
        if (root->val == sum && root->left == NULL && root->right == NULL) return true;
        sum -= root->val;
        bool flag = recursive(root->left, sum);
        flag = flag || recursive(root->right, sum);
        sum += root->val;
        return flag;
    }
public:
    bool hasPathSum(TreeNode* root, int sum) {
        return recursive(root, sum);
    }
};