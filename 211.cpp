/*
 * Approach: Dictionary Trie (same as #208)
 * Time complexity: -   || 76.98% (148 ms)
 * Space complexity: -  || 61.05% (43 MB)
 * Note: deal with '*' recursively
 */
class WordDictionary {
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
    bool recursiveSearch(string& word, int start, TrieNode* node) {
        for (int i = start; i < word.size(); i++) {
            if (word[i] != '.') {
                node = node->children[word[i]-'a'];
                if (!node) return false;
            } else {
                for (int j = 0; j < 26; j++) {
                    if (node->children[j] && recursiveSearch(word, i + 1, node->children[j])) {
                        return true;
                    }
                }
                return false;
            }
        }
        return node->end;
    }
public:
    /** Initialize your data structure here. */
    WordDictionary() {
        root = new TrieNode();
    }
    
    /** Adds a word into the data structure. */
    void addWord(string word) {
        TrieNode *cur = root;
        for (char c : word) {
            if (!cur->children[c-'a']) cur->children[c-'a'] = new TrieNode();
            cur = cur->children[c-'a'];
        }
        cur->end = true;
    }
    
    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word) {
        return recursiveSearch(word, 0, root);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */