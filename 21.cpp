/*
 * Approach: Linked list pointer operation
 * Time complexity: O(m+n)   || 100.00%
 * Space complexity: O(1)    || 99.81%
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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (!l1) return l2;
        if (!l2) return l1;
        ListNode *p, *q, *ret, *tmpp;
        if (l1->val < l2->val) p = l1, q = l2;
        else p = l2, q = l1;
        ret = p, tmpp = p->next;
        while (tmpp != NULL) {
            if (q == NULL) {
                p->next = tmpp;
                break;
            }
            if (tmpp->val < q->val) {
                p->next = tmpp;
                p = p->next;
                tmpp = tmpp->next;
            }
            else {
                p->next = q;
                p = p->next;
                q = q->next;
            }
        }
        if (tmpp == NULL) p->next = q;
        return ret;
    }
};

/* method 1: 88.46% time, 100.00% space, least code.
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (l1 == NULL) return l2;
        if (l2 == NULL) return l1;
        if (l1->val < l2->val) {
            l1->next = mergeTwoLists(l1->next, l2);
            return l1;
        }
        else {
            l2->next = mergeTwoLists(l1, l2->next);
            return l2;
        }
    }
};
*/

/* method 2: performance same as method 0
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (l1 == NULL) return l2;
        if (l2 == NULL) return l1;
        ListNode *head, *p;
        if (l1->val < l2->val) {
            head = l1;
            l1 = l1->next;
        }
        else {
            head = l2;
            l2 = l2->next;
        }
        p = head;
        while (l1 && l2) {
            if (l1->val < l2->val) {
                p->next = l1;
                l1 = l1->next;
            }
            else {
                p->next = l2;
                l2 = l2->next;
            }
            p = p->next;
        }
        if (l1) p->next = l1;
        else p->next = l2;
        return head;
    }
};
*/