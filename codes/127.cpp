/*
 * Approach: BFS
 * Time complexity: O(mn)   || 70.53% (132 ms)
 * Space complexity: O(n)  || 75.00% (13.2 MB)
 * Note: represent words in graph, then find the shortest path from begin to end
 * Note: obviously use Breadth First Search
 */
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> dict(wordList.begin(), wordList.end());
        queue<string> q;
        int length = 1;
        q.push(beginWord);
        dict.erase(beginWord);
        
        while (!q.empty()) {
            int n = q.size();
            for (int i = 0; i < n; i++) {
                string word = q.front();
                q.pop();
                if (word == endWord) return length;
                for (int j = 0; j < word.size(); j++) {
                    char c = word[j];
                    for (int k = 0; k < 26; k++) {
                        word[j] = 'a' + k;
                        if (dict.find(word) != dict.end()) {
                            q.push(word);
                            dict.erase(word);
                        }
                    }
                    word[j] = c;
                }
            }
            length++;
        }
        return 0;
    }
};
/*
 * Approach: BFS (Bidirectional)
 * Time complexity: O(mn)   || 94.65% (40 ms)
 * Space complexity: O(n)  || 100.00% (12.6 MB)
 * Note: start from `begin` as well as `end`, meet together to speed up to (logN/2)^m
 * Note: log(N)^m / log(N/2)^m = log(N/2)^m     (which means faster)
 */
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> dict(wordList.begin(), wordList.end()), begin({beginWord}), end({endWord});
        if (dict.find(endWord) == dict.end()) {
            return 0;
        }
        int length = 2;

        while (!begin.empty() && !end.empty()) {
            if (begin.size() > end.size()) swap(begin, end); // with minimum out-degree bidirectional
            unordered_set<string> visited;
            for (auto it = begin.begin(); it != begin.end(); it++) {
                string word = *it;
                for (int j = 0; j < word.size(); j++) {
                    char c = word[j];
                    for (int k = 0; k < 26; k++) {
                        word[j] = 'a' + k;
                        if (end.find(word) != end.end()) return length;
                        if (dict.find(word) != dict.end()) {
                            visited.insert(word);
                            dict.erase(word);
                        }
                    }
                    word[j] = c;
                }
            }
            length++;
            begin.swap(visited);
        }
        return 0;
    }
};
/*
 * Approach: BFS (Bidirectional) (use map but not traverse 26 alphas)
 * Time complexity: O(mn)   || 50.97% (192 ms)
 * Space complexity: O(n)  || 15.91% (40.1 MB)
 */
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> dict(wordList.begin(), wordList.end()), begin({beginWord}), end({endWord});
        unordered_map<string, vector<string>> combo;
        if (dict.find(endWord) == dict.end()) {
            return 0;
        }
        int length = 2;
        for (string w : wordList) {
            for (int i = 0; i < w.size(); i++) {
                string wtemp = w.substr(0, i) + '*' + w.substr(i + 1, w.size() - 1 - i);
                vector<string> listtemp;
                if (combo.count(wtemp) > 0) listtemp = combo[wtemp];
                listtemp.push_back(w);
                combo[wtemp] = listtemp;
            }
        }

        while (!begin.empty() && !end.empty()) {
            if (begin.size() > end.size()) swap(begin, end);
            unordered_set<string> temp;
            for (auto it = begin.begin(); it != begin.end(); it++) {
                string word = *it;
                for (int j = 0; j < word.size(); j++) {
                    char c = word[j];
                    word[j] = '*';
                    for (string w : combo[word]) {
                        if (end.find(w) != end.end()) return length;
                        if (dict.find(w) != dict.end()) {
                            temp.insert(w);
                            dict.erase(w);
                        }
                    }
                    word[j] = c;
                }
            }
            length++;
            begin.swap(temp);
        }
        return 0;
    }
};