/*
 * Approach: 2-pointers
 * Time complexity: O(n)   || 97.97% (20 ms)
 * Space complexity: O(1)  || 76.59% (13.9 MB)
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
    bool isPalindrome(ListNode* head) {
        if (!head || !head->next) return true;
        // 1: reach mid
        ListNode *fast = head, *slow = head;
        while (fast && fast->next) {
            fast = fast->next->next;
            slow = slow->next;
        }
        if (fast) slow = slow->next; // odd nodes
        // 2: reverse latter part
        fast = slow->next;
        ListNode *tail = slow;
        while (fast) {
            tail->next = fast->next;
            fast->next = slow;
            slow = fast;
            fast = tail->next;
        }
        // 3: check from head and mid
        while (slow) {
            if (head->val != slow->val) return false;
            head = head->next;
            slow = slow->next;
        }
        return true;
    }
};