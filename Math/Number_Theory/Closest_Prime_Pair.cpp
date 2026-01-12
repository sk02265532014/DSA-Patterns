// Problem: Closest Prime Numbers in Range
// Pattern: Number Theory - Sieve of Eratosthenes
//
// Key Idea:
// - Use Sieve of Eratosthenes to precompute primes up to 'right'
// - Collect all primes within [left, right]
// - Find adjacent prime pair with minimum difference
//
// Time Complexity: O(n log log n)
// Space Complexity: O(n)

class Solution {
public:
    vector<int> closestPrimes(int left, int right) {
        vector<bool> isPrime(right + 1, true);
        isPrime[0] = isPrime[1] = false;

        // Sieve of Eratosthenes
        for (int i = 2; i * i <= right; i++) {
            if (isPrime[i]) {
                for (int j = i * i; j <= right; j += i)
                    isPrime[j] = false;
            }
        }

        int prev = -1;
        int minDiff = INT_MAX;
        vector<int> ans = {-1, -1};

        // Scan primes in range
        for (int i = max(2, left); i <= right; i++) {
            if (isPrime[i]) {
                if (prev != -1 && i - prev < minDiff) {
                    minDiff = i - prev;
                    ans = {prev, i};
                }
                prev = i;
            }
        }

        return ans;
    }
};
