/*
 * Approach: two pointers and recursive
 * Time complexity: O(nlog(n))   || 98.06% (24 ms)
 * Space complexity: O(n)  || 90.91% (24.4 MB)
 */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
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
    TreeNode* recursive(ListNode* head, ListNode* tail) {
        if (head == tail) return NULL;
        ListNode *mid = head, *fast = head;
        while (fast != tail && fast->next != tail) {
            mid = mid->next;
            fast = fast->next->next;
        }
        TreeNode *root = new TreeNode(mid->val);
        root->left = recursive(head, mid);
        root->right = recursive(mid->next, tail);
        return root;
    }
public:
    TreeNode* sortedListToBST(ListNode* head) {
        return recursive(head, NULL);
    }
};