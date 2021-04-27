/*
 * Approach: regularity
 * Time complexity: O(n)   || 86.45% (48 ms)
 * Space complexity: O(1)  || 100.00% (14.6 MB)
 * Note: ListA -- L1 = L1' + L, where L1 is the length of A, L1' is its private part, L is the public part
 * Note: ListB -- L2 = L2' + L
 * Note: Therefore we just need to move forward ahead L2 - L1 = L2' - L1' steps, suppose L2 longer than L1
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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int lenA = 0, lenB = 0, step;
        ListNode *curA = headA, *curB = headB;
        while (curA) {
            lenA++;
            curA = curA->next;
        }
        while (curB) {
            lenB++;
            curB = curB->next;
        }
        if (lenA > lenB) curA = headA, curB = headB, step = lenA - lenB;
        else curA = headB, curB = headA, step = lenB - lenA;
        while (step--) curA = curA->next;
        while (curA) {
            if (curA == curB) return curA;
            curA = curA->next;
            curB = curB->next;
        }
        return NULL;
    }
};