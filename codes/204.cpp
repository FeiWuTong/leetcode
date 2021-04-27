/*
 * Approach: The Sieve of Eratosthenes
 * Time complexity: O(nloglogn)   || 43.78% (172 ms)
 * Space complexity: O(n)  || 100.00% (6.6 MB)
 */
class Solution {
public:
    int countPrimes(int n) {
        if (n <= 2) return 0;
        vector<bool> isPrime(n, true);
        for (int i = 2; i <= n / i; i++) {
            if (!isPrime[i]) continue;
            for (int j = i * i; j < n; j += i) {
                isPrime[j] = false;
            }
        }
        return count(isPrime.begin() + 2, isPrime.end(), true);
    }
};
/*
 * Approach: slightly accelerate
 * Time complexity: O(nloglogn)   || 60.02% (132 ms)
 * Space complexity: O(n)  || 100.00% (6.6 MB)
 */
class Solution {
public:
    int countPrimes(int n) {
        if (n <= 2) return 0;
        vector<bool> isPrime(n, true);
        for (int i = 4; i < n; i += 2) isPrime[i] = false;
        for (int i = 3; i <= n / i; i++) {
            if (!isPrime[i]) continue;
            for (int j = i * i; j < n; j += 2 * i) {
                isPrime[j] = false;
            }
        }
        return count(isPrime.begin() + 2, isPrime.end(), true);
    }
};