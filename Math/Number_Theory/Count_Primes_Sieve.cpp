// Problem: Count Primes
// Pattern: Number Theory - Sieve of Eratosthenes
//
// Key Idea:
// - Use a boolean array to mark prime numbers
// - For each prime i, mark all multiples starting from i*i as non-prime
// - Count how many primes exist less than n
//
// Time Complexity: O(n log log n)
// Space Complexity: O(n)

class Solution {
public:
    int countPrimes(int n) {
        if (n < 2) return 0;

        vector<bool> isPrime(n, true);
        isPrime[0] = false;
        isPrime[1] = false;

        int count = 0;

        for (int i = 2; i < n; i++) {
            if (isPrime[i]) {
                count++;

                // Mark multiples of i as non-prime
                for (long long j = 1LL * i * i; j < n; j += i) {
                    isPrime[j] = false;
                }
            }
        }
        return count;
    }
};
