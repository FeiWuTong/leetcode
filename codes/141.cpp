/*
 * Approach: two pointers
 * Time complexity: O(n)   || 50.05% (12 ms)
 * Space complexity: O(1)  || 100.00% (7.7 MB)
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
    bool hasCycle(ListNode *head) {
        if (head == NULL) return false;
        ListNode *slow = head;
        ListNode *fast = head->next;
        while (slow != fast) {
            if (fast == NULL || fast->next == NULL) return false;
            slow = slow->next;
            fast = fast->next->next;
        }
        return true;
    }
};
/*
 * Approach: hash
 * Time complexity: O(n)   || 17.90% (20 ms)
 * Space complexity: O(n)  || 75.00% (9.8 MB)
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        unordered_set<ListNode*> check;
        ListNode *cur = head;
        while (cur) {
            if (check.count(cur)) return true;
            check.insert(cur);
            cur = cur->next;
        }
        return false;
    }
};