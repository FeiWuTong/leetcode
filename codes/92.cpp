/*
 * Approach: one pass
 * Time complexity: O(n)   || 54.57%
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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        ListNode fakeH = ListNode(0);
        fakeH.next = head;
        ListNode *pre = &fakeH, *cur, *rear, *last;
        int i = 0;
        while (++i < m) pre = pre->next;
        rear = pre->next->next;
        last = pre->next;
        while (++i <= n) {
            cur = rear;
            rear = cur->next;
            cur->next = pre->next;
            pre->next = cur;
        }
        last->next = rear;
        return fakeH.next;
    }
};