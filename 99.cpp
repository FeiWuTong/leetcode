/*
 * Approach: inorder (straight forward)
 * Time complexity: O(n)   || 99.22% (20 ms)
 * Space complexity: O(n)  || 5.26% (53.2 MB)
 * Note: inorder, the output will like 2-3-4-5-6, i.e. ascend, then we need to find 6-3-4-5-2 that leftmost node bigger than its right one, and the second leftmost smaller than its left one
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
    TreeNode *first = NULL, *sec = NULL, *pre = NULL;
    void recursive(TreeNode* root) {
        if (root != NULL) {
            recursive(root->left);
            if (first == NULL && pre != NULL && pre->val >= root->val) {
                first = pre;
                sec = root;
            }
            else if(first != NULL && pre->val >= root->val) {
                sec = root;
                return;
            }
            pre = root;
            recursive(root->right);
        }
    }
public:
    void recoverTree(TreeNode* root) {
        recursive(root);
        //assert(first != NULL && sec != NULL);
        swap(first->val, sec->val);
    }
};
/*
 * Approach: Morris Traversal
 * Time complexity: O(n)   || 97.41% (24 ms)
 * Space complexity: O(1)  || 5.26% (53.5 MB)
 */
class Solution {
private:
    // record two mistake
    TreeNode *first = NULL, *sec = NULL, *pre = NULL;
    // record (inorder-todo)
    void record(TreeNode*& cur) {
        if (pre != NULL && pre->val >= cur->val) {
            if (first == NULL) first = pre;
            sec = cur;
        }
        pre = cur;
        cur = cur->right;
    }
public:
    void recoverTree(TreeNode* root) {
        // Morris
        TreeNode *cur = root, *temp = NULL;
        while (cur != NULL) {
            if (cur->left == NULL) record(cur);
            else {
                temp = cur->left;
                while (temp->right != NULL && temp->right != cur) 
                    temp = temp->right;
                if (temp->right == NULL) {
                    temp->right = cur;
                    cur = cur->left;
                }
                else {
                    record(cur);
                    temp->right = NULL;
                }
            }
        }
        //assert(first != NULL && sec != NULL);
        swap(first->val, sec->val);
    }
};