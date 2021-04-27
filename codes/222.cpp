/*
 * Approach: Recursive (DFS)
 * Time complexity: O(n)   || 54.42% (44 ms)
 * Space complexity: O(n)  || 15.56% (31.1 MB)
 * Note: Traverse all node
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
    int countNodes(TreeNode* root) {
        if (!root) return 0;
        else return countNodes(root->left) + countNodes(root->right) + 1;
    }
};
/*
 * Approach: Recursive (DFS)
 * Time complexity: O((logn)^2)   || 54.42% (44 ms)
 * Space complexity: O(n)  || 44.21% (30.9 MB)
 * Note: Just calculate all height
 */
class Solution {
private:
    int height(TreeNode* root) {
        return root ? 1 + height(root->left) : -1;
    }
public:
    int countNodes(TreeNode* root) {
        int h = height(root);
        if (h < 0) return 0;
        else {
            // last node in right subtree, left subtree is a full tree of height h-1
            if (height(root->right) == h - 1) return (1 << h) + countNodes(root->right);
            // last node in left subtree, right subtree is a full tree of height h-2
            else return (1 << (h - 1)) + countNodes(root->left);
        }
    }
};
/*
 * Approach: iterative
 * Time complexity: O((logn)^2)   || 73.76% (440 ms)
 * Space complexity: O(n)  || 26.73% (31 MB)
 */
class Solution {
private:
    int height(TreeNode* root) {
        int h = -1;
        while (root) {
            h++;
            root = root->left;
        }
        return h;
    }
public:
    int countNodes(TreeNode* root) {
        int cnt = 0, h = height(root);
        while (root) {
            if (height(root->right) == h - 1) {
                cnt += 1 << h;
                root = root->right;
            } else {
                cnt += 1 << (h - 1);
                root = root->left;
            }
            h--;
        }
        return cnt;
    }
};
/*
 * Approach: Recursive
 * Time complexity: O((logn)^2)   || 73.76% (440 ms)
 * Space complexity: O(n)  || 26.73% (31 MB)
 * Note: check whether the left subtree is perfect
 */
class Solution {
public:
    int countNodes(TreeNode* root) {
        if (!root) return 0;
        int num = 1;
        TreeNode *curR(root->left), *curL(root->left);
        while (curR) {
            curL = curL->left;
            curR = curR->right;
            // right / left subtree's node count + root
            num = num << 1;
        }
        return num + (curL ? countNodes(root->left) : countNodes(root->right));
    }
};