/*
 * Approach: No
 * Time complexity: O(n)   || 89.74% (24 ms)
 * Space complexity: O(1)  || 5.66% (13.5 MB)
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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode *fake = new ListNode(0, head);
        head = fake;
        while (head->next) {
            if (head->next->val == val) head->next = head->next->next;
            else head = head->next;
        }
        return fake->next;
    }
};