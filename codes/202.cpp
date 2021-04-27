/*
 * Approach: hashtable
 * Time complexity: O(1)   || 100.00% (0 ms)
 * Space complexity: O(1)  || 100.00% (6.4 MB)
 */
class Solution {
private:
    int next(int n) {
        int ret = 0, num;
        while (n) {
            num = n % 10;
            ret += num * num;
            n /= 10;
        }
        return ret;
    }
public:
    bool isHappy(int n) {
        unordered_set<int> check;
        do {
            if (n == 1) return true;
            check.insert(n);
            n = next(n);
        } while (check.count(n) == 0);
        return false;
    }
};
/*
 * Approach: two-pointer (no hashtable)
 * Time complexity: O(1)   || 100.00% (0 ms)
 * Space complexity: O(1)  || 100.00% (5.9 MB)
 * Note: similar to linked list cycle detection
 */
class Solution {
private:
    int next(int n) {
        int ret = 0, num;
        while (n) {
            num = n % 10;
            ret += num * num;
            n /= 10;
        }
        return ret;
    }
public:
    bool isHappy(int n) {
        int slow = n, fast = n;
        do {
            slow = next(slow);
            fast = next(next(fast));
            if (fast == 1) return true;
        } while (slow != fast);
        return false;
    }
};