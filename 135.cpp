/*
 * Approach: greedy
 * Time complexity: O(n)   || 24.27% (48 ms)
 * Space complexity: O(1)  || 7.69% (17.4 MB)
 */
class Solution {
public:
    int candy(vector<int>& ratings) {
        if (ratings.size() == 0) return 0;
        int ret = 1, highest = 0, highestR = 1, lastR = 1;
        for (int i = 1; i < ratings.size(); i++) {
            if (ratings[i] < ratings[i-1]) {
                ret += i - highest + (highestR == 1);
                if (highestR > 1) highestR--;
                lastR = 1;
            } else if (ratings[i] == ratings[i-1]) {
                ret += 1;
                lastR = 1;
                highestR = 1;
                highest = i;
            } else {
                highestR = lastR + 1;
                lastR = highestR;
                ret += highestR;
                highest = i;
            }
        }
        return ret;
    }
};
/*
 * Approach: more concise and faster one
 * Time complexity: O(n)   || 33.67% (44 ms)
 * Space complexity: O(1)  || 7.69% (17.9 MB)
 * Note: scan from left to right, and right to left, to ensure higher rated child get 1 more candy
 */
class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        vector<int> num(n, 1);
        for (int i = 1; i < n; i++) {
            if (ratings[i] > ratings[i-1]) num[i] = num[i-1] + 1;
        }
        for (int i = n - 1; i > 0; i--) {
            if (ratings[i-1] > ratings[i]) num[i-1] = max(num[i-1], num[i] + 1);
        }
        int sum = 0;
        for (int i = 0; i < n; i++) sum += num[i];
        return sum;
    }
};