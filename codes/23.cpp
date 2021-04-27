/*
 * Approach: Prior Queue (not best one but good one)
 * Time complexity: O(Nlogk) || 99.81%
 * Space complexity: O(k)    || 99.63%
 * Note: k is the number of linked lists and N is the total number of nodes.
 * Note2: can reuse #21 approach, although performance is worse, but easy.
 * Note3: remove recursion and deal every 2 group can also reach Nlogk.(best answer)
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
    struct cmp {
        bool operator()(const ListNode *l, const ListNode *r) {
            return l->val > r->val;
        }
    };
    ListNode* mergeKLists(vector<ListNode *>& lists) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        priority_queue<ListNode *, vector<ListNode *>, cmp> q;
        for (ListNode *l : lists) {
            if (l) q.push(l);
        }
        if (q.empty()) return NULL;
        ListNode *res = q.top();
        q.pop();
        if (res->next) q.push(res->next);
        ListNode *tail = res;
        while (!q.empty()) {
            tail->next = q.top();
            q.pop();
            tail = tail->next;
            if(tail->next) q.push(tail->next);
        }
        return res;
    }
};

/* #21 extension
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode *res = NULL;
        for (int i = 0; i < lists.size(); i++) {
            res = mergeTwoLists(res, lists[i]);
        }
        return res;
    }
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (l1 == NULL) return l2;
        if (l2 == NULL) return l1;
        if (l1->val < l2->val) {
            l1->next = mergeTwoLists(l1->next, l2);
            return l1;
        }
        else {
            l2->next = mergeTwoLists(l1, l2->next);
            return l2;
        }
    }
};
*/

/* #21 no recursion and deal every 2 lists as a group
 * best answer: time - 100.00%, space - 99.88%
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        int len = lists.size();
        while (len) {
            if (len == 1) return lists[0];
            int j = 0;
            for (int i = 0; i < len; i += 2) {
                if (i == len - 1) lists[j++] = lists[i];
                else lists[j++] = mergeTwoLists(lists[i], lists[i+1]);
            }
            len = j;
        }
        return NULL;
    }
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (l1 == NULL) return l2;
        if (l2 == NULL) return l1;
        ListNode *head, *p;
        if (l1->val < l2->val) {
            head = l1;
            l1 = l1->next;
        }
        else {
            head = l2;
            l2 = l2->next;
        }
        p = head;
        while (l1 && l2) {
            if (l1->val < l2->val) {
                p->next = l1;
                l1 = l1->next;
            }
            else {
                p->next = l2;
                l2 = l2->next;
            }
            p = p->next;
        }
        if (l1) p->next = l1;
        else p->next = l2;
        return head;
    }
};
*/