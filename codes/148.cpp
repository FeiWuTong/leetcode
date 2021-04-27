/*
 * Approach: Non-recursive (bottom-to-up, i.e. reverse the up-to-bottom recursion)
 * Time complexity: O(nlogn)   || 94.65% (36 ms)
 * Space complexity: O(1)  || 17.50% (13 MB)
 * Note: Sort a linked list in O(n log n) time using constant space complexity
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
    // after merge, `head` is the tail of the merged sorted linked list
    void merge(ListNode* p, ListNode* q, ListNode*& head) {
        while (p && q) {
            if (p->val > q->val) {
                head->next = q;
                head = q;
                q = q->next;
            } else {
                head->next = p;
                head = p;
                p = p->next;
            }
        }
        head->next = p ? p : q;
        while (head->next) head = head->next;
    }
    // return next split list's head
    ListNode* split(ListNode* p, int len) {
        for (int i = 1; p && i < len; i++) p = p->next;
        if (p == NULL) return NULL;
        ListNode *pn = p->next;
        p->next = NULL;
        return pn;
    }
public:
    ListNode* sortList(ListNode* head) {
        ListNode *dummy = new ListNode(0);
        dummy->next = head;
        ListNode *left, *right, *tail;
        int len = 0;
        while (head) {
            len++;
            head = head->next;
        }

        for (int step = 1; step < len; step <<= 1) {
            head = dummy->next;
            tail = dummy;
            while (head) {
                left = head;
                right = split(left, step);
                head = split(right, step);
                merge(left, right, tail);
            }
        }
        return dummy->next;
    }
};
/*
 * Approach: same as above, but more concise and complex
 * Time complexity: O(nlogn)   || 24.37% (80 ms)
 * Space complexity: O(1)  || 27.50% (12.7 MB)
 */
class Solution {
public:
    ListNode* sortList(ListNode* head) {
        bool done = (!head);
        // Keep partitioning our list into bigger sublists length. Starting with a size of 1 and doubling each time
        for (int step = 1; !done; step <<= 1) {
            done = true;
            ListNode **next_ptr = &head;
            ListNode *remaining = head;
            ListNode *list[2];
            do {
                // Split off two sublists of size step
                for (auto& sub_head : list) {
                    sub_head = remaining;
                    ListNode *tail = NULL;
                    for (int i = 0; i < step && remaining; ++i, remaining = remaining->next) {
                        tail = remaining;
                    }
                    // Terminate our sublist
                    if (tail) tail->next = NULL;
                }

                // We're done if these are the first two sublists in this pass
                // and they encompass the entire primary list
                done &= !remaining;

                // If we have two sublists, merge them into one
                if (list[1]) {
                    while (list[0] || list[1]) {
                        int idx = (!list[1] || list[0] && list[0]->val <= list[1]->val) ? 0 : 1;
                        *next_ptr = list[idx];
                        next_ptr = &(**next_ptr).next;
                        list[idx] = list[idx]->next;
                    }
                    // Terminate our new sublist
                    *next_ptr = nullptr;
                } else {
                    // Only a single sublist, no need to merge, just attach to the end
                    *next_ptr = list[0];
                }
            } while (remaining);
        }
    return head;
    }
};
/*
 * Approach: #2 with buffer to speed up (with lower constant time cost)
 * Time complexity: O(nlogn)   || 94.46% (36 ms)
 * Space complexity: O(1)  || 27.50% (12.7 MB)
 * Note: #2 each time just split and merge 2 sublists (i.e. adjacent)
 * Note: but here we use buffer, to temporarily store n sublists
 * Note: which can do more thing in one round (outermost loop)
 */
class Solution {
private:
    // split into sublists of the requested size, returns number sublists and remaining list
    pair<int, ListNode*> split(ListNode* head, int step, ListNode* l[], int list_size) {
        int cnt = 0;
        while (head && cnt < list_size) {
            l[cnt++] = head;
            ListNode *tail = nullptr;
            for (int i = 0; i < step && head; i++, head = head->next) {
                tail = head;
            }
            if (tail) tail->next = nullptr;
        }
        return make_pair(cnt, head);
    }
    // Merge two sorted lists into one, the head and tail of the new list is returned
    pair<ListNode*, ListNode*> merge(ListNode* p1, ListNode* p2) {
        ListNode *head, *tail = nullptr;
        ListNode **next_ptr = &head;
        while (p1 || p2) {
            ListNode **cur = (!p2 || p1 && p1->val <= p2->val) ? &p1 : &p2;
            *next_ptr = tail = *cur;
            *cur = (*cur)->next;
            next_ptr = &(*next_ptr)->next;
        }
        *next_ptr = nullptr;
        return make_pair(head, tail);
    }
public:
    ListNode* sortList(ListNode* head) {
        constexpr int buf_sz = 8;
        ListNode *buf[buf_sz];
        bool done = (!head);

        for (int step = 1; !done; step *= buf_sz) {
            done = true;
            ListNode *remaining = head;
            ListNode *tail = nullptr;
            ListNode **next_ptr = &head;
            int n;
            do {
                std::tie(n, remaining) = split(remaining, step, buf, buf_sz);
                done &= (!remaining);
                // Keep merging until a single sorted list is made
                for (; n > 1; n = (n + 1) / 2) {
                    for (int i = 0; i < n / 2; i++) {
                        std::tie(buf[i], tail) = merge(buf[i*2], buf[i*2+1]);
                    }
                    if (n % 2) buf[n/2] = buf[n-1];
                }
                *next_ptr = buf[0];
                if (tail) next_ptr = &(tail->next);
            } while (remaining);
        }
        return head;
    }
};
/*
 * Approach: quicksort (most concise)
 * Time complexity: O(nlogn)   || 6.67% (716 ms)
 * Space complexity: O(logn)  || 15.00% (15.1 MB)
 */
class Solution {
public:
    ListNode* sortList(ListNode* head, ListNode* tail = nullptr) {
        if (head != tail) {
            ListNode* smaller;
            ListNode** smaller_next = &smaller;
            for (ListNode** prev = &head->next; *prev != tail; ) {
                if (head->val > (**prev).val) {
                    *smaller_next = *prev;
                    smaller_next = &((**smaller_next).next);
                    *prev = (**prev).next;
                } else {
                    prev = &((**prev).next);
                }
            }
            *smaller_next = head;
            head->next = sortList(head->next, tail);
            head = sortList(smaller, head);
        }
        return head;
    }
};