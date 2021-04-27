/*
 * Approach: 2 pointers
 * Time complexity: O(n)   || 98.86%
 * Space complexity: O(1)  || 100.00%
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
    ListNode* partition(ListNode* head, int x) {
        ListNode Fakehead = ListNode(0);
        Fakehead.next = head;
        ListNode *pre, *cur = &Fakehead, *boundary;
        while (cur->next && cur->next->val < x) cur = cur->next;
        pre = cur;
        cur = cur->next;
        if (cur) {
            boundary = cur; 
            while (cur->next) {
                if (cur->next->val < x) {
                    pre->next = cur->next;
                    cur->next = cur->next->next;
                    pre = pre->next;
                    pre->next = boundary;
                }
                else cur = cur->next;
            }
        }
        return Fakehead.next;
    }
};