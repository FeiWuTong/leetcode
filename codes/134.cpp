/*
 * Approach: greedy
 * Time complexity: O(n)   || 54.15% (8 ms)
 * Space complexity: O(1)  || 5.88% (10 MB)
 */
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int used = 0, fill = 0, start = 0;
        for (int i = 0; i < gas.size(); i++) {
            fill += gas[i] - cost[i];
            if (fill < 0) {
                used -= fill;
                fill = 0;
                start = i + 1;
            }
        }
        return fill >= used ? start : -1;
    }
};