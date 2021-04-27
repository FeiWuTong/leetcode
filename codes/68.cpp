/*
 * Approach: NO
 * Time complexity: -   || 100.00%
 * Space complexity: -  || 100.00%
 */
class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> ret;
        int nr_ret = 0;
        for (int i = 0; i < words.size();) {
            int width = words[i].size();
            ret.push_back(words[i++]);
            int count = 0, space;
            while (i + count < words.size() && width + words[i+count].size() + 1 <= maxWidth) {
                width += words[i+count].size() + 1;
                count++;
            }
            if (count < 2) {
                space = maxWidth - width;
                if (count == 1) {
                    if (i + count == words.size()) {
                        ret[nr_ret].append(" " + words[i++]);
                        ret[nr_ret].append(string(space, ' '));
                    }
                    else ret[nr_ret].append(string(space+1, ' ') + words[i++]);
                }
                else ret[nr_ret].append(string(space, ' '));
            }
            else {
                if (i + count == words.size()) {
                    while (count--) ret[nr_ret].append(" " + words[i++]);
                    ret[nr_ret].append(string(maxWidth - width, ' '));
                    ret[nr_ret] += '\0';
                    break;
                }
                space = (maxWidth - width) / count;
                if (space * count < maxWidth - width) {
                    for (int j = maxWidth - width - space * count; j > 0; j--) {
                        ret[nr_ret].append(string(space+2, ' ') + words[i++]);
                        count--;
                    }
                }
                while (count--) {
                    ret[nr_ret].append(string(space+1, ' ') + words[i++]);
                }
            }
            ret[nr_ret] += '\0';
            nr_ret++;
        }
        return ret;
    }
};