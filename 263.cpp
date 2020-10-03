/*
 * Approach: No
 * Time complexity: -   || 44.66% (4 ms)
 * Space complexity: O(1)  || 50.63% (6 MB)
 */
class Solution {
private:
    void removeN(int& num, int n) {
        while (num % n == 0) num /= n;
    }
public:
    bool isUgly(int num) {
        if (num <= 0) return false;
        removeN(num, 2);
        removeN(num, 3);
        removeN(num, 5);
        return num == 1;
    }
};
// or
class Solution {
public:
    bool isUgly(int num) {
        for (int i = 2; i < 6 && num; i++) {
            while (num % i == 0) num /= i;
        }
        return num == 1;
    }
};