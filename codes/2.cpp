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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* l3 = new ListNode(0);
        ListNode* curr = l3;
        int carry = 0;
        while (l1 != NULL || l2 != NULL) {
            if (l1 != NULL) {
                curr->val += l1->val;
                l1 = l1->next;
            }
            if (l2 != NULL) {
                curr->val += l2->val;
                l2 = l2->next;
            }
            curr->val += carry;
            carry = curr->val / 10;
            curr->val %= 10;
            if (l1 != NULL || l2 != NULL || carry) {
                curr->next = new ListNode(0);
                curr = curr->next;
            }
        }
        if (carry > 0) {
            curr->val = carry;
        }
        return l3;
    }
};