/*
 * Approach: Hashtable
 * Time complexity: O(n)   || 76.45% (76 ms)
 * Space complexity: O(n)  || 50.00% (22.9 MB)
 */
class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        vector<string> ret;
        unordered_map<string, bool> check;
        for (int i = 0; i + 9 < s.size(); i++) {
            string cur = s.substr(i, 10);
            if (check.count(cur)) {
                if (check[cur]) {
                    ret.push_back(cur);
                    check[cur] = false;
                }
            }
            else check[cur] = true;
        }
        return ret;
    }
};
/*
 * Approach: bitset - redefine hash function and make use of overlapping part
 * Time complexity: O(n)   || 98.03% (16 ms)
 * Space complexity: O(n)  || 100.00% (7.6 MB)
 * Note: #1 solution indeed take 20n time, 10n in hash function, but #2 only 1n in hash function
 * Note: besides due to string only contain 4 letters (2-bits), normal hash will waste lots of space to avoid collision
 * Note: bitset only use 20-bits integer (as hash) to cover all case, i.e. 1M space is enough
 */
class Solution {
private:
    int char2int(char c) {
        switch (c) {
            case 'A': return 0;
            case 'C': return 1;
            case 'G': return 2;
            default : return 3;
        }
    }
public:
    vector<string> findRepeatedDnaSequences(string s) {
        vector<string> ret;
        if (s.size() <= 10) return ret;
        bitset<1<<20 > once;
        bitset<1<<20 > more;
        int myhash = 0;
        // calculate first 10-length substring's hash
        for (int i = 0; i < 10; i++) {
            myhash = (myhash << 2) | char2int(s[i]);
        }
        once.set(myhash);
        // calculate hash for 9-length before plus 1-length current (position i)
        int mask = (1 << 20) - 1;
        for (int i = 10; i < s.size(); i++) {
            myhash = ((myhash << 2) & mask) | char2int(s[i]);
            if (more[myhash]) continue;
            if (once[myhash]) {
                ret.push_back(s.substr(i - 9, 10));
                more.set(myhash);
            } else {
                once.set(myhash);
            }
        }
        return ret;
    }
};