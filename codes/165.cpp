/*
 * Approach: string-stream
 * Time complexity: O(n)   || 100.00% (0 ms)
 * Space complexity: O(n)  || 100.00% (6.2 MB)
 * Note: istringstream suspend at space/<CR> character (equal to split)
 */
class Solution {
public:
    int compareVersion(string version1, string version2) {
        for (auto& c: version1) if (c == '.') c = ' ';
        for (auto& c: version2) if (c == '.') c = ' ';
        istringstream s1(version1), s2(version2);
        while (1) {
            int n1, n2;
            if (not(s1 >> n1)) n1 = 0;
            if (not(s2 >> n2)) n2 = 0;
            if (not s1 and not s2) return 0;
            if (n1 > n2) return 1;
            if (n1 < n2) return -1;
        }
    }
};