/*
 * Approach: No
 * Time complexity: O(n^2)   || 74.89% (28 ms)
 * Space complexity: O(1)  || 100.00% (8.8 MB)
 * Note: insertion sort
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
class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        if (head == NULL || head->next == NULL) return head;
        ListNode *p = head->next, *tail = head;
        while (p) {
            if (p->val >= tail->val) {
                tail = p;
            } else {
                tail->next = p->next;
                if (p->val <= head->val) {
                    p->next = head;
                    head = p;
                } else {
                    ListNode *cur = head;
                    while (p->val > cur->next->val) cur = cur->next;
                    p->next = cur->next;
                    cur->next = p;
                }
            }
            p = tail->next;
        }
        return head;
    }
};