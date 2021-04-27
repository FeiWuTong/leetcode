/*
 * Approach: Reverse and Jump over
 * Time complexity: O(2n) ~ O(n)    || 100.00%
 * Space complexity: O(1)           || 100.00%
 * Note: need to check overflow firstly
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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        if (k == 0 || k == 1) return head;
        ListNode *res = new ListNode(0);
        res->next = head;
        ListNode *goon = head, *newNode = res;
        while (head) {
            for (int i = 0; i < k; i++) {
                if (goon == NULL) {
                    newNode->next = head;
                    return res->next;
                }
                goon = goon->next;
            }
            ListNode *tmp, *jump = head;
            for (int i = 0; i < k; i++) {
                tmp = head->next;
                head->next = newNode->next;
                newNode->next = head;
                head = tmp;
            }
            newNode = jump;
            newNode->next = NULL;
        }
        return res->next;
    }
};