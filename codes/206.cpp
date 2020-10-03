/*
 * Approach: Recursive
 * Time complexity: O(n)   || 96.70% (4 ms)
 * Space complexity: O(n)  || 7.59% (8.2 MB)
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
private:
    ListNode *newH;
    ListNode* recursive(ListNode* head) {
        if (head->next) recursive(head->next)->next = head;
        else newH = head;
        return head;
    }
public:
    ListNode* reverseList(ListNode* head) {
        if (!head || !head->next) return head;
        recursive(head);
        head->next = NULL;
        return newH;
    }
};
/*
 * Approach: iteratively
 * Time complexity: O(n)   || 96.70% (4 ms)
 * Space complexity: O(1)  || 65.99% (7.8 MB)
 * Note: dummy head is also ok, and straightforward 
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (!head || !head->next) return head;
        ListNode *cur = head->next;
        head->next = NULL;
        while (cur) {
            ListNode *next = cur->next;
            cur->next = head;
            head = cur;
            cur = next;
        }
        return head;
    }
};