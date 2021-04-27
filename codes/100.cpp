/*
 * Approach: Recursion
 * Time complexity: O(n)   || 35.23%
 * Space complexity: O(n)  || 99.45%
 * Note: use queue or stack can remove recursion
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
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (p == NULL && q == NULL) return true;
        if (p == NULL || q == NULL) return false;
        if (p->val != q->val) return false;
        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
};
/*
 * Approach: Stack
 * Time complexity: O(n)   || 100.00%
 * Space complexity: O(n)  || 99.45%
 */
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        stack<TreeNode*> s;
        s.push(p), s.push(q);
        while (!s.empty()) {
            q = s.top();
            s.pop();
            p = s.top();
            s.pop();
            if (!p && !q) continue;
            if (!p || !q || p->val != q->val) return false;
            s.push(p->right), s.push(q->right);
            s.push(p->left), s.push(q->left);
        }
        return true;
    }
};