/*
 * Approach: BFS, same as #127
 * Time complexity: O(mn)   || 29.70% (972 ms)
 * Space complexity: -  || 45.00% (178.3 MB)
 * Note: `erase` should do after scanning over a level
 */
class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        vector<vector<string>> ret;
        unordered_set<string> dict(wordList.begin(), wordList.end()), visited;
        queue<vector<string>> q;
        int length = 1, limit = wordList.size();
        q.push({beginWord});
        dict.erase(beginWord);

        while (!q.empty()) {
            if (length > limit) break;
            for (string w : visited) dict.erase(w);
            visited.clear();
            int n = q.size();
            for (int i = 0; i < n; i++) {
                vector<string> path = q.front();
                q.pop();
                string word = path.back();
                for (int j = 0; j < word.size(); j++) {
                    char c = word[j];
                    for (int k = 0; k < 26; k++) {
                        word[j] = 'a' + k;
                        if (dict.find(word) != dict.end()) {
                            vector<string> newpath = path;
                            newpath.push_back(word);
                            if (word == endWord) {
                                limit = length;
                                ret.push_back(newpath);
                                break;
                            }
                            else {
                                q.push(newpath);
                                visited.insert(word);
                            }
                        }
                    }
                    word[j] = c;
                }
            }
            length++;
        }
        return ret;
    }
};
/*
 * Approach: BFS, same as #127, but push_back by backtracking (DFS)
 * Time complexity: O(mn)   || 92.56% (60 ms)
 * Space complexity: -  || 100.00% (14.2 MB)
 * Note: just take a bit change to #127-#2
 */
class Solution {
private:
    void backtracking(unordered_map<string, vector<string>>& nexts, 
        vector<vector<string>>& ret, vector<string>& path, 
        string beginWord, string endWord) {
            if (beginWord == endWord) ret.push_back(path);
            else {
                for (string w : nexts[beginWord]) {
                    path.push_back(w);
                    backtracking(nexts, ret, path, w, endWord);
                    path.pop_back();
                }
            }
        }
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        vector<vector<string>> ret;
        unordered_set<string> dict(wordList.begin(), wordList.end()), begin({beginWord}), end({endWord});
        if (dict.find(endWord) == dict.end()) {
            return ret;
        }
        vector<string> path(1, beginWord);
        unordered_map<string, vector<string>> nexts;
        bool flip = false, reach = false;
        dict.erase(beginWord);
        dict.erase(endWord);

        while (!begin.empty() && !end.empty()) {
            if (begin.size() > end.size()) {
                swap(begin, end);
                flip ^= 1;
            }
            unordered_set<string> visited;
            for (auto it = begin.begin(); it != begin.end(); it++) {
                string word = *it;
                for (int j = 0; j < word.size(); j++) {
                    char c = word[j];
                    for (int k = 0; k < 26; k++) {
                        word[j] = 'a' + k;
                        if (end.find(word) != end.end()) {
                            reach = true;
                            flip ? nexts[word].push_back(*it) : nexts[*it].push_back(word);
                        }
                        else if (!reach && dict.find(word) != dict.end()) {
                            visited.insert(word);
                            flip ? nexts[word].push_back(*it) : nexts[*it].push_back(word);
                        }
                    }
                    word[j] = c;
                }
            }
            if (reach) break;
            for (string w : visited) dict.erase(w);
            begin.swap(visited);
        }
        if (reach) backtracking(nexts, ret, path, beginWord, endWord);
        return ret;
    }
};