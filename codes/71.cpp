/*
 * Approach: Stack
 * Time complexity: -   || 76.86%
 * Space complexity: -  || 100.00%
 */
class Solution {
public:
    string simplifyPath(string path) {
        vector<pair<int, int>> index;
        string ret = "/";
        int single = 1;
        for (int i = 0; i < path.size();) {
            assert(path[i] == '/');
            if (++i == path.size()) break;
            if (path[i] == '/') continue;
            if (path[i] == '.') {
                i++;
                if (i == path.size()) break;
                if (path[i] == '/') continue;
                if (path[i] == '.') {
                    if (++i == path.size() || i < path.size() && path[i] == '/') {
                        if (index.size()) index.pop_back();
                        if (i == path.size()) break;
                        continue;
                    }
                    else index.push_back(make_pair(i-2, 3));
                }
                else index.push_back(make_pair(i-1, 2));
                while (++i < path.size() && path[i] != '/') {
                    index[index.size()-1].second++;
                }
                continue;
            }
            // dir name push
            index.push_back(make_pair(i, 1));
            while (++i < path.size() && path[i] != '/') {
                index[index.size()-1].second++;
            }
        }
        if (index.size() == 0) return ret;
        int st = 0;
        ret += string(path, index[st].first, index[st].second); 
        while (++st < index.size()) {
            ret += "/";
            ret += string(path, index[st].first, index[st].second);
        }
        return ret;
    }
};