/*
 * Approach: recursive (DFS)
 * Time complexity: O(n)   || 23.53% - 92.89% (52 ms - 16 ms)
 * Space complexity: O(n)  || 9.52% (24.2 MB - 23.6 MB)
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
    // optimize by using hash_map, to 16 ms
    unordered_map<int, int> table;
    void initTable(vector<int>& inorder) {
        for (int i = 0; i < inorder.size(); i++) { table.emplace(inorder[i], i); }
    }
    TreeNode* buildRecursive(vector<int>& preorder, vector<int>& inorder, int pre_s, int pre_e, int in_s, int in_e) {
        if (pre_s >= pre_e) { return NULL; }

        int pos = table[preorder[pre_s]];
        int leftsize = pos - in_s;
        /*
        auto pos = find(inorder.begin() + in_s, inorder.begin() + in_e, \
        preorder[pre_s]);
        int leftsize = pos - inorder.begin() - in_s;
        */

        TreeNode *root = new TreeNode(preorder[pre_s], \
        buildRecursive(preorder, inorder, pre_s + 1, pre_s + 1 + leftsize, in_s, in_s + leftsize), \
        buildRecursive(preorder, inorder, pre_s + 1 + leftsize, pre_e, in_s + leftsize + 1, in_e));

        return root;
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        initTable(inorder);
        return buildRecursive(preorder, inorder, 0, preorder.size(), 0, inorder.size());
    }
};
/*
 * Approach: stack (DFS) (hard to think)
 * Time complexity: O(n)   || 100.00% (4 ms)
 * Space complexity: O(n)  || 23.81% (20.9 MB)
 */
class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int preS = preorder.size();
        if (preS == 0) return NULL;
        int i = 0, j = 0;
        stack<TreeNode*> st;
        TreeNode *cur = NULL, *lastroot = NULL;

        TreeNode *root = new TreeNode(preorder[i++]);
        st.push(root);
        while (i < preS) {
            // If the value of stack top equals to inorder[j], it means
            // next immediate preorder value should not be its left, since 
            // based on inorder, its left value has been processed
            if (!st.empty() && st.top()->val == inorder[j]) {
                // find the leftmost node, and its left part finished
                lastroot = st.top();
                st.pop();
                j++;
            }
            else {
                cur = new TreeNode(preorder[i++]);
                if (lastroot) {
                    lastroot->right = cur;
                    lastroot = NULL;
                }
                else st.top()->left = cur;
                st.push(cur);
            }
        }
        return root;
    }
};