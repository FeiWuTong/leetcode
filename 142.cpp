/*
 * Approach: two pointers (like #141)
 * Time complexity: O(n)   || 94.28% (8 ms)
 * Space complexity: O(n)  || 100.00% (7.8 MB)
 * Note: L1 = cycle entry - head, L2 = meet point - cycle entry, C = cycle length
 * Note: then 2 * (L1 + L2 + n1 * C) = L1 + L2 + n2 * C, where the former is slow pointer, latter is fast pointer
 * Note: we can get L1 = (n2 - 2 * n1 - 1) * C + (C - L2)
 * Note: which means meet point go ahead and finish this cycle can meet a new pointer start from head at entry
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
    ListNode *detectCycle(ListNode *head) {
        if (head == NULL) return NULL;
        ListNode *slow = head;
        ListNode *fast = head;
        ListNode *entry = head;
        while (fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) {
                while (slow != entry) {
                    slow = slow->next;
                    entry = entry->next;
                }
                return entry;
            }
        }
        return NULL;
    }
};
/*
 * Approach: hash (same as #141)
 * Time complexity: O(n)   || 18.23% (24 ms)
 * Space complexity: O(n)  || 50.00% (9.9 MB)
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        unordered_set<ListNode*> check;
        ListNode *cur = head;
        while (cur) {
            if (check.count(cur)) return cur;
            check.insert(cur);
            cur = cur->next;
        }
        return NULL;
    }
};