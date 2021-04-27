/*
 * Approach: queue (BFS)
 * Time complexity: O(n)   || 94.65% (4 ms)
 * Space complexity: O(n)  || 100.00% (12.8 MB)
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ret;
        if (!root) return ret;
        queue<TreeNode*> last, cur;
        TreeNode* cur_node;
        last.push(root);
        while (!last.empty()) {
            vector<int> temp;
            while (!last.empty()) {
                cur_node = last.front();
                temp.push_back(cur_node->val);
                if (cur_node->left) cur.push(cur_node->left);
                if (cur_node->right) cur.push(cur_node->right);
                last.pop();
            }
            ret.push_back(temp);
            swap(last, cur);
        }
        return ret;
    }
};