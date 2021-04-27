/*
 * Approach: DP
 * Time complexity: O(n^2)   || 57.82% (20 ms) -> 97.30% (4 ms)
 * Space complexity: O(n)  || 84.91% (9.6 MB) -> 100.00% (7.8 MB)
 * Note: loop j should from i-1 to 0, not 0 to i-1, to avoid some repeat work
 */
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        if (wordDict.size() == 0) return false;
        unordered_set<string> dict(wordDict.begin(), wordDict.end());
        /* accelerate part
        unordered_set<string> dict;
        int maxlen = 0;
        for (string word : wordDict) {
            dict.insert(word);
            maxlen = max(maxlen, int(word.size()));
        }
        */
        vector<bool> dp(s.size() + 1, false);
        dp[0] = true;
        // i is the len of substr of s
        for (int i = 1; i <= s.size(); i++) {
            for (int j = i - 1; j >= 0; j--) {
                /* accelerate part
                if (i - j > maxlen) break;
                */
                if (dp[j] && dict.find(s.substr(j, i - j)) != dict.end()) {
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[s.size()];
    }
};
/*
 * Approach: queue (BFS) (another effective method)
 * Time complexity: O(n^2)   || 23.30% (36 ms)
 * Space complexity: O(n)  || 54.72% (13.3 MB)
 * Note: Use `visited` to avoid repeat work
 */
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        if (wordDict.size() == 0) return false;
        unordered_set<string> dict(wordDict.begin(), wordDict.end());
        queue<int> q;
        unordered_set<int> visited;
        q.push(0);
        while (!q.empty()) {
            int start = q.front();
            q.pop();
            if (visited.find(start) == visited.end()) {
                visited.insert(start);
                // substr -> [start, i)
                for (int i = start + 1; i <= s.size(); i++) {
                    if (dict.find(s.substr(start, i - start)) != dict.end()) {
                        if (i == s.size()) return true;
                        q.push(i);
                    }
                }
            }
        }
        return false;
    }
};
/*
 * Approach: DP with DFS (fast one and smart)
 * Time complexity: O(n^2)   || 100.00% (0 ms)
 * Space complexity: O(n)  || 100.00%(8.2 MB)
 * Note: use maxlen to break impossible length, and dp[i] != -1 represents status visited
 */
class Solution {
private:
    bool wordBreakHelp(string& s, unordered_set<string>& wordDict, int i, vector<int>& dp, int& maxlen){
        if (i == s.size()) return true;
        if (dp[i] != -1) return dp[i];
        for (int j = i + 1; j <= s.size(); j++) {
            if (j - i > maxlen) break;
            if (wordDict.find(s.substr(i, j - i)) != wordDict.end()) {
                dp[i] = wordBreakHelp(s, wordDict, j, dp, maxlen);
                if (dp[i]) return true;
            }
        }    
        dp[i] = false;
        return false;
    }
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dict;
        vector<int> dp(s.size(), -1);
        int maxlen = 0;
        for (string word : wordDict) {
            dict.insert(word);
            maxlen = max(maxlen, int(word.size()));
        }
        return wordBreakHelp(s, dict, 0, dp, maxlen);
    }
};