/*
 * Approach: two pointer
 * Time complexity: O(n)   || 46.65%
 * Space complexity: O(1)  || 100.00%
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
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == NULL) return head;
        ListNode *ret, *front, *back;
        ret = front = back = head;
        int l = 1;
        for (int i = 0; i < k; i++) {
            if (front->next == NULL) break;
            front = front->next;
            l++;
        }
        if (front->next == NULL) {
            int step = l - 1 - k % l;
            while (step--) back = back->next;
        }
        else {
            while (front->next != NULL) {
                front = front->next;
                back = back->next;
            }
        }
        if (back->next == NULL) {
            ret = head;
        }
        else {
            ret = back->next;
            back->next = NULL;
            front->next = head;
        }
        return ret;
    }
};