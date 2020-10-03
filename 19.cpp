/*
 * Approach: One Pass Two Pointer
 * Time complexity: O(L)   || 100.00%
 * Space complexity: O(1)    || 100.00%
 * Note: Provide the other two methods.
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *f, *s;
        f = head, s = head;
        while (n--) s = s->next;
        if (s == NULL) {
            return head->next;
        }
        while (s->next != NULL) {
            s = s->next;
            f = f->next;
        }
        f->next = f->next->next;
        return head;
    }
};