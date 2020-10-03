/*
 * Approach: Recursive (DFS) (same as #133)
 * Time complexity: O(n)   || 50.61% (16 ms)
 * Space complexity: O(n)  || 100.00% (16.2 MB)
 */
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
private:
    unordered_map<Node*, Node*> check;
public:
    Node* copyRandomList(Node* head) {
        if (head == NULL) return NULL;
        if (check.find(head) == check.end()) {
            check[head] = new Node(head->val);
            check[head]->random = copyRandomList(head->random);
            check[head]->next = copyRandomList(head->next);
        }
        return check[head];
    }
};