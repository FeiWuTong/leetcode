/*
 * Approach: Dictionary Trie (dfs, recursive) (reference #208)
 * Time complexity: -   || 97.16% (48 ms)
 * Space complexity: -  || 61.74% (32.5 MB)
 * Note: Use words to build the dictionary trie and traverse board to find if it is some words' prefix character
 */
class Solution {
private:
    /** Dictionary Trie definition and its root */
    struct TrieNode
    {
        string word;
        TrieNode *children[26];
        TrieNode() {
            memset(children, NULL, sizeof(children));
        }
    };
    TrieNode *root;
    // use words to build the trie
    void buildTrie(vector<string>& words) {
        root = new TrieNode();
        for (string w : words) {
            TrieNode *p = root;
            for (char c : w) {
                int i = c - 'a';
                if (!p->children[i]) p->children[i] = new TrieNode();
                p = p->children[i];
            }
            p->word = w;
        }
    }
    /** dfs to traverse all possible ways */
    vector<string> ret;
    int m, n;
    void dfs(vector<vector<char>>& board, int i, int j, TrieNode* node) {
        char c = board[i][j];
        if (c == '#' || !node->children[c-'a']) return;
        node = node->children[c-'a'];
        if (!node->word.empty()) {
            ret.push_back(node->word);
            node->word.clear();
        }
        board[i][j] = '#';
        if (i > 0) dfs(board, i - 1, j, node);
        if (j > 0) dfs(board, i, j - 1, node);
        if (i < m - 1) dfs(board, i + 1, j, node);
        if (j < n - 1) dfs(board, i, j + 1, node);
        board[i][j] = c;
    }
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        m = board.size(), n = board[0].size();
        buildTrie(words);
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                dfs(board, i, j, root);
            }
        }
        return ret;
    }
};
/*
 * Approach: Only dfs + table
 * Time complexity: -   || Time Limit Exceeded
 * Space complexity: -  || 
 * Note: Indeed this is also a solution, but can not deal with the larger test (too many duplicate characters)
 * Note: #1 solution can do with duplicate characters and build a not big trie (i.e. special case, can do all words in 1 time), but also can not deal with too larger case
 * Note: submit this solution, you can find why can #1 can pass #34 test case but this one cannot
 */
class Solution {
private:
    bool is_adj(int i1, int j1, int i2, int j2) {
        return abs(i1 - i2) + abs(j1 - j2) == 1;
    }
    // this word ok, abort current dfs and go next
    bool ok;
    vector<string> ret;
    void dfs(string& w, vector<vector<bool>>& check, vector<vector<pair<int, int>>>& table, int start, int i2, int j2) {
        if (start == w.size()) {
            ret.push_back(w);
            ok = true;
            return;
        }
        int i1, j1;
        for (int i = 0; !ok && i < table[w[start]-'a'].size(); i++) {
            std::tie(i1, j1) = table[w[start]-'a'][i];
            if (check[i1][j1] || (i2 != -1 && !is_adj(i1, j1, i2, j2))) continue;
            check[i1][j1] = true;
            dfs(w, check, table, start + 1, i1, j1);
            check[i1][j1] = false;
        }
    }
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        vector<vector<pair<int, int> > > table(26, vector<pair<int, int> >());
        int m = board.size(), n = board[0].size();
        // table store the characters' positions
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                table[board[i][j] - 'a'].push_back(make_pair(i, j));
            }
        }
        // check if visited
        vector<vector<bool>> check(m, vector<bool>(n, false));
        for (string& w : words) {
            ok = false;
            /* when we add this line and add original line with else, we can pass #34 and #35 test case
             * with 38.96% (252 ms) and 91.89% (13.6 MB)
             * which can test and verify our suppose in `Note`
            if (w.size() <= m * n && w.size() > 12 && count(w.begin(), w.begin() + 12, 'a') >= 11) dfs(w, check, table, 12, -1, -1);
             */
            dfs(w, check, table, 0, -1, -1);
        }
        return ret;
    }
};