/*
 * Approach: No
 * Time complexity: O(1)   || 98.16% (12 ms)
 * Space complexity: O(1)  || 98.67% (7.9 MB)
 * Note: stupid question that cannot delete current node, just copy value and delete next node
 */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void deleteNode(ListNode* node) {
        ListNode *temp = node->next;
        *node = *temp;
        delete(temp);
    }
};