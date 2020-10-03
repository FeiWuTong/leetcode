/*
 * Approach: Prefix Tree Design
 * Time complexity: -   || 53.53% (120 ms)
 * Space complexity: -  || 26.49% (44.6 MB)
 */
class Trie {
private:
    struct TrieNode
    {
        bool end;
        TrieNode *children[26];
        TrieNode() {
            end = false;
            memset(children, NULL, sizeof(children));
        }
    };
    TrieNode *root;
public:
    /** Initialize your data structure here. */
    Trie() {
        root = new TrieNode();
    }

    /** destructor */
    ~Trie() {
        clear(root);
    }

    /** destructor's function */
    void clear(TrieNode* root) {
        for (auto& child : root->children) {
            if (child) clear(child);
        }
        delete root;
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        TrieNode *cur = root;
        for (char c : word) {
            if (!cur->children[c-'a']) cur->children[c-'a'] = new TrieNode();
            cur = cur->children[c-'a'];
        }
        cur->end = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        TrieNode *cur = root;
        for (char c : word) {
            if (!cur->children[c-'a']) return false;
            cur = cur->children[c-'a'];
        }
        return cur->end;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        TrieNode *cur = root;
        for (char c : prefix) {
            if (!cur->children[c-'a']) return false;
            cur = cur->children[c-'a'];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */