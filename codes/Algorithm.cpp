/**
 * Union Find
 * ===== construct
 * UF(int n);
 * ===== function
 * Union(int p, int q);
 * connected(int p, int q);
 * getCount();
 */
class UF {
private:
    // union elements' amount
    int count;
    // roots' size (or weight)
    vector<int> size;
    // every tree node's parent
    vector<int> parent;
    /* get the root of node x */
    int find(int x) {
        while (parent[x] != x) {
            // path compact
            parent[x] = parent[parent[x]];
            x = parent[x];
        }
        return x;
    }
public:
    // construct
    UF(int n) {
        count = n;
        size.resize(n);
        parent.resize(n);
        for (int i = 0; i < n; i++) {
            size[i] = 1;
            parent[i] = i;
        }
    }
    // union p and q
    void Union(int p, int q) {
        int rootP = find(p);
        int rootQ = find(q);
        if (rootP == rootQ) return;
        // smaller tree link to bigger tree, keep balance
        if (size[rootP] > size[rootQ]) {
            parent[rootQ] = rootP;
            size[rootP] += size[rootQ];
        } else {
            parent[rootP] = rootQ;
            size[rootQ] += size[rootP];
        }
        count--;
    }
    // judge whether p and q are connected
    bool connected(int p, int q) {
        return find(p) == find(q);
    }
    // get the amount of unions
    int getCount() {
        return count;
    }
};

/**
 * MorrisTraverse
 * O(n) time, O(1) space
 * ===== function
 * inorderTraversal(TreeNode* root)
 * preorderTraversal(TreeNode* root)
 * postorderTraversal(TreeNode* root);
 */
class MorrisTraverse {
private:
    vector<int> ret;    // modify here to meet needs
    void reverse(TreeNode* from, TreeNode* to) {
        if (from == to) return;
        TreeNode *x = from, TreeNode *y = from->right, *z;
        while (x != to) {
            z = y->right;
            y->right = x;
            x = y;
            y = z;
        }
    }
    void reverseDo(TreeNode* from, TreeNode* to) {
        reverse(from, to);
        TreeNode *p = to;
        while (true) {
            ret.push_back(p->val);  // modify here to meet needs
            if (p == from) break;
            p = p->right;
        }
        reverse(to, from);
    }
public:
    vector<int> postorderTraversal(TreeNode* root) {
        TreeNode *dummy = new TreeNode(0);
        dummy->left = root;
        root = dummy;
        while (root) {
            if (root->left) {
                TreeNode *pre = root->left;
                while (pre->right && pre->right != root) pre = pre->right;
                if (pre->right == NULL) {
                    pre->right = root;
                    root = root->left;
                } else {
                    reverseDo(root->left, pre);
                    pre->right = NULL;
                    root = root->right;
                }
            } else {
                root = root->right;
            }
        }
        return ret;
    }
};