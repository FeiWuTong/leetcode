/*
 * Approach: Straight-forward (or use stack instead of vector)
 * Time complexity: O(n)   || 87.01% (40 ms)
 * Space complexity: O(n)  || 5.88% (15.6 MB)
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
    void reorderList(ListNode* head) {
        vector<ListNode*> temp;
        ListNode *cur = head;
        while (cur) {
            temp.push_back(cur);
            cur = cur->next;
        }
        ListNode *nextp;
        int n = temp.size();
        if (n <= 2) return;
        for (int i = 0; i < (n + 1) / 2; i++) {
            nextp = temp[i]->next;
            temp[i]->next = temp[n-1-i];
            temp[n-1-i]->next = nextp;
        }
        temp[n/2]->next = NULL;
    }
};
/*
 * Approach: two-pointers
 * Time complexity: O(n)   || 75.68% (52 ms)
 * Space complexity: O(1)  || 5.88% (14.4 MB)
 * Note: we can observe the regularity in reorder list: 1-2-3-4-5-6 ==> 1-6-2-5-3-4
 * Note: i.e. 1-2-3 in normal order but 4-5-6 in reverse order
 * Note: so we can divide it into 3 parts, I. Find the middle node; II. reverse back part; III. link front part with back part
 */
class Solution {
public:
    void reorderList(ListNode* head) {
        if (!head || !head->next) return;
        // I. Find the middle node (1-2-_3_-4-5-6)
        ListNode *slow = head;
        ListNode *fast = head;
        while (fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        // II. reverse back part (1-2-3-4-5-6 ==> 1-2-3-6-5-4)
        fast = slow->next;
        while (fast->next) {
            ListNode *cur = fast->next;
            fast->next = cur->next;
            cur->next = slow->next;
            slow->next = cur;
        }
        // III. link front part with back part (1-2-3-6-5-4 ==> 1-6-2-5-3-4)
        ListNode *mid = slow;
        fast = slow->next;
        slow = head;
        while (slow != mid) {
            mid->next = fast->next;
            fast->next = slow->next;
            slow->next = fast;
            slow = fast->next;
            fast = mid->next;
        }
    }
};