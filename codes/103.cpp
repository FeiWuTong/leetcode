/*
 * Approach: stack (BFS)
 * Time complexity: O(n)   || 24.38% (8 ms)
 * Space complexity: O(n)  || 100.00% (12.4 MB)
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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ret;
        if (!root) return ret;
        stack<TreeNode*> last, cur;
        TreeNode* cur_node;
        bool turn = true;
        last.push(root);
        while (!last.empty()) {
            vector<int> temp;
            while (!last.empty()) {
                cur_node = last.top();
                temp.push_back(cur_node->val);
                if (turn) {
                    if (cur_node->left) cur.push(cur_node->left);
                    if (cur_node->right) cur.push(cur_node->right);
                }
                else {
                    if (cur_node->right) cur.push(cur_node->right);
                    if (cur_node->left) cur.push(cur_node->left);
                }
                last.pop();
            }
            ret.push_back(temp);
            swap(last, cur);
            turn ^= 1;
        }
        return ret;
    }
};
/*
 * Approach: queue (BFS) (same as #102)
 * Time complexity: O(n)   || 83.99% (4 ms)
 * Space complexity: O(n)  || 100.00% (12.4 MB)
 */
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ret;
        if (!root) return ret;
        queue<TreeNode*> last, cur;
        TreeNode* cur_node;
        bool turn = false;
        last.push(root);
        while (!last.empty()) {
            vector<int> temp(last.size());
            int i = turn ? last.size() - 1 : 0;
            while (!last.empty()) {
                cur_node = last.front();
                temp[i] = cur_node->val;
                if (cur_node->left) cur.push(cur_node->left);
                if (cur_node->right) cur.push(cur_node->right);
                last.pop();
                turn ? i-- : i++;
            }
            ret.push_back(temp);
            swap(last, cur);
            turn ^= 1;
        }
        return ret;
    }
};