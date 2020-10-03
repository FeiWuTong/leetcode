/*
 * Approach: stack
 * Time complexity: average O(1)   || 32.81% (88 ms)
 * Space complexity: O(h)  || 6.52% (27.7 MB)
 * Note: although next() need to push right-child-left-subtree (may take O(n))
 * Note: we only need to traverse 1 time, i.e. total time cost is n, and call next() n times, so average is O(1)
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
class BSTIterator {
private:
    stack<TreeNode*> s;
public:
    BSTIterator(TreeNode* root) {
        while (root) {
            s.push(root);
            root = root->left;
        }
    }
    
    /** @return the next smallest number */
    int next() {
        TreeNode *p = s.top();
        s.pop();
        TreeNode *cur = p->right;
        while (cur) {
            s.push(cur);
            cur = cur->left;
        }
        return p->val;
    }
    
    /** @return whether we have a next smallest number */
    bool hasNext() {
        return !s.empty();
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */