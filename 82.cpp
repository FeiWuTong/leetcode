/*
 * Approach: NO
 * Time complexity: -   || 91.84%
 * Space complexity: -  || 100.00%
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
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == NULL || head->next == NULL) return head; 
        ListNode *p = head->next;
        ListNode *link = NULL, *cur = head;
        bool stay = true;
        while (p) {
            if (p->val == cur->val) stay = false;
            else {
                if (stay) {
                    if (link) {
                        link->next = cur;
                        link = cur;
                    }
                    else {
                        link = cur;
                        head = link;
                    }
                }
                else stay = true;
                cur = p;
            }
            p = p->next;
        }
        if (stay) {
            if (link) {
                link->next = cur;
                link = cur;
            }
            else {
                link = cur;
                head = link;
            }
        }
        if (link) link->next = NULL;
        return link == NULL ? link : head;
    }
};
/*
 * Approach: NO (more concise)
 * Time complexity: -   || 99.69%
 * Space complexity: -  || 100.00%
 */
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == NULL) return head;
        ListNode fakeHead = ListNode(0);
        fakeHead.next = head;
        ListNode *pre = &fakeHead, *cur = head;
        while (cur) {
            while (cur->next && cur->next->val == cur->val) cur = cur->next;
            if (pre->next == cur) pre = cur;
            else pre->next = cur->next;
            cur = cur->next;
        }
        return fakeHead.next;
    }
};