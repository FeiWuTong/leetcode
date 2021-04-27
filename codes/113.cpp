/*
 * Approach: Recursive (DFS)
 * Time complexity: O(n)   || 80.93% (12 ms)
 * Space complexity: O(n)  || 39.47% (20.1 MB)
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
    void recursive(vector<vector<int>>& ret, vector<int>& cur, TreeNode* root, int sum) {
        if (!root->left && !root->right && sum == 0) {
            ret.push_back(cur);
        }
        else {
            if (root->left) {
                cur.push_back(root->left->val);
                recursive(ret, cur, root->left, sum - root->left->val);
                cur.pop_back();
            }
            if (root->right) {
                cur.push_back(root->right->val);
                recursive(ret, cur, root->right, sum - root->right->val);
                cur.pop_back();
            }
        }
    }
public:
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> ret;
        vector<int> cur;
        if (root) {
            cur.push_back(root->val);
            recursive(ret, cur, root, sum - root->val);
        }
        return ret;
    }
};

// use cur[0] as current sum, 62.89%, 36.84%
class Solution {
private:
    int pathsum;
    void recursive(vector<vector<int>>& ret, vector<int>& cur, TreeNode* root) {
        if (!root->left && !root->right && cur[0] == pathsum) {
            ret.push_back(vector<int>(cur.begin() + 1, cur.end()));
        }
        else {
            if (root->left) {
                cur.push_back(root->left->val);
                cur[0] += root->left->val;
                recursive(ret, cur, root->left);
                cur.pop_back();
                cur[0] -= root->left->val;
            }
            if (root->right) {
                cur.push_back(root->right->val);
                cur[0] += root->right->val;
                recursive(ret, cur, root->right);
                cur.pop_back();
                cur[0] -= root->right->val;
            }
        }
    }
public:
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> ret;
        vector<int> cur(1, 0);
        if (root) {
            pathsum = sum;
            cur.push_back(root->val);
            cur[0] += root->val;
            recursive(ret, cur, root);
        }
        return ret;
    }
};