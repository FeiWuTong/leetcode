/*
 * Approach: DP + DFS (modify #139-#3)
 * Time complexity: -   || 99.79% (4 ms)
 * Space complexity: -  || 96.97% (10.3 MB)
 */
class Solution {
private:
    vector<string> ret;
    void wordBreakHelp(string& s, unordered_set<string>& wordDict, int i, vector<int>& dp, int& maxlen, string& cur, int last){
        if (i == s.size()) {
            ret.push_back(cur.substr(0, cur.size() - 1));
            dp[last] = 1;
            return;
        }
        if (dp[i] == 0) return;
        for (int j = i + 1; j <= s.size(); j++) {
            if (j - i > maxlen) break;
            string temp = s.substr(i, j - i);
            if (wordDict.find(temp) != wordDict.end()) {
                cur += temp + " ";
                wordBreakHelp(s, wordDict, j, dp, maxlen, cur, i);
                cur = cur.substr(0, cur.size() - temp.size() - 1);
                if (dp[i] == 1) dp[last] = 1;
            }
        }
        if (dp[last] != 1 && dp[i] != 1) dp[last] = 0;
    }
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dict;
        vector<int> dp(s.size(), -1);
        int maxlen = 0;
        for (string word : wordDict) {
            dict.insert(word);
            maxlen = max(maxlen, int(word.size()));
        }
        string cur;
        wordBreakHelp(s, dict, 0, dp, maxlen, cur, 0);
        return ret;
    }
};
/*
 * Approach: hashmap + DFS (also a top-down dp method)
 * Time complexity: -   || 97.64% (8 ms)
 * Space complexity: -  || 96.97% (10.6 MB)
 */
class Solution {
private:
    unordered_map<string, vector<string>> m;
    int maxlen = 0;
    void combine(string& word, vector<string>& pre) {
        for (int i = 0; i < pre.size(); i++) {
            pre[i] += " " + word;
        }
    }
    vector<string> DFS(string s, unordered_set<string>& dict) {
        if (m.count(s)) return m[s];
        vector<string> ret;
        if (dict.count(s)) ret.push_back(s);
        for (int i = 1; i < s.size(); i++) {
            if (s.size() - i > maxlen) continue;
            string word = s.substr(i);
            if (dict.count(word)) {
                string rem = s.substr(0, i);
                vector<string> pre;
                pre = DFS(rem, dict);
                combine(word, pre);
                ret.insert(ret.end(), pre.begin(), pre.end());
            }
        }
        m[s] = ret;
        return ret;
    }
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dict;
        for (string word : wordDict) {
            dict.insert(word);
            maxlen = max(maxlen, int(word.size()));
        }
        return DFS(s, dict);
    }
};
/*
 * We can also modify #139-#1 or #2 with vector<int, vector<int>> dp or unordered_map<int, vector<int>> m
 * to record next step (e.g. dp[i] tells how to step from i)
 * Then use DFS to traverse dp
 */
/*
 * Approach: BFS + DFS (modify #139-#2)
 * Time complexity: -   || 99.79% (4 ms)
 * Space complexity: -  || 100.00% (9.3 MB)
 */
class Solution {
private:
    void dfs(vector<string>& ret, unordered_map<int, vector<int>>& visited, int start, string& s, string path) {
        if (start == s.size()) ret.push_back(path.substr(1));
        else {
            for (int next : visited[start]) {
                string word = s.substr(start, next - start);
                dfs(ret, visited, next, s, path + " " + word);
            }
        }
    }
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        vector<string> ret;
        if (wordDict.size() == 0) return ret;
        unordered_set<string> dict;
        int maxlen = 0;
        for (string word : wordDict) {
            dict.insert(word);
            maxlen = max(maxlen, int(word.size()));
        }
        queue<int> q;
        unordered_map<int, vector<int>> visited;
        q.push(0);
        while (!q.empty()) {
            int start = q.front();
            q.pop();
            if (visited.count(start) == 0) {
                visited[start] = vector<int>();
                for (int i = start + 1; i <= s.size() && i - start <= maxlen; i++) {
                    if (dict.find(s.substr(start, i - start)) != dict.end()) {
                        visited[start].push_back(i);
                        q.push(i);
                    }
                }
            }
        }
        if (visited.count(s.size()) == 0) return ret;
        dfs(ret, visited, 0, s, "");
        return ret;
    }
};