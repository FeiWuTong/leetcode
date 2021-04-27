/*
 * Approach: Two Pointer
 * Time complexity: O(n)   || 100.00%
 * Space complexity: O(1)  || 100.00%
 * Note: Concise Version behind
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
    ListNode* swapPairs(ListNode* head) {
        if (!head || !head->next) return head;
        ListNode *a = head, *b = a->next, *tmp;
        head = b;
        while (b) {
            if (b->next) {
                if (b->next->next) a->next = b->next->next;
                else {
                    a->next = b->next;
                    b->next = a;
                    break;
                }
            }
            else a->next = NULL;
            tmp = b->next;
            b->next = a;
            b = a->next;
            a = tmp;
        }
        return head;
    }
};

/*
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if (!head || !head->next) return head;
        ListNode *p1 = head, *p2 = p1->next, *last = NULL;
        head = p2;
        while (p2) {
            p1->next = p2->next;
            p2->next = p1;
            if (last) last->next = p2;
            last = p1;
            p1 = p1->next;
            if (p1) p2 = p1->next;
            else break;
        }
        return head;
    }
};
*/