/*
 * Approach: loop
 * Time complexity: -   || 100.00% (0 ms)
 * Space complexity: -  || 18.49% (6.3 MB)
 */
class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int> res;
        int start = 1, round = 1, base = 1;
        while (round <= 9) {
            for (int i = 0; i <= 9 - round; i++) {
                int num = start + i * base;
                if (num > high) return res;
                else if (num >= low && num <= high) res.push_back(num);
            }
            round++;
            base = base * 10 + 1;
            start = start * 10 + start % 10 + 1;
        }
        return res;
    }
};
/*
 * Approach: BFS
 * Time complexity: -   || 100.00% (0 ms)
 * Space complexity: -  || 30.46% (6.3 MB)
 */
class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int> res;
        queue<int> q;
        for (int i = 1; i <= 9; i++) q.push(i);
        while (!q.empty()) {
            int num = q.front();
            q.pop();
            if (num >= low && num <= high) res.push_back(num);
            else if (num > high) break;
            int last = num % 10 + 1;
            if (last < 10) q.push(num * 10 + last);
        }
        return res;
    }
};