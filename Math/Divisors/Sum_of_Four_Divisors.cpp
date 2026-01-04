// Problem: Sum of Four Divisors
// Pattern: Number Theory (Divisor Counting)
// Key Idea:
// Iterate up to sqrt(n), count divisors and their sum
// Early stop if divisor count exceeds 4
// Time Complexity: O(sqrt(n)) per number


class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {
        int ans = 0;

        // For each number, calculate sum of its divisors
        // only if it has exactly 4 divisors
        for (int i = 0; i < nums.size(); i++) {
            ans += divisors(nums[i]);
        }

        return ans;
    }

    // Returns sum of divisors if n has exactly 4 divisors
    // Otherwise returns 0
    int divisors(int n) {
        int count = 0;  // number of divisors
        int sum = 0;    // sum of divisors

        // Iterate only till sqrt(n) for efficiency
        for (int i = 1; i * i <= n; i++) {

            // If i is a divisor
            if (n % i == 0) {

                // If i and n/i are different divisors
                if (i != n / i) {
                    count += 2;            // i and n/i
                    sum += i + (n / i);
                } 
                // If i is the square root (perfect square case)
                else {
                    count += 1;
                    sum += i;
                }
            }

            // Early exit: no need to continue if more than 4 divisors
            if (count > 4) return 0;
        }

        // Return sum only if exactly 4 divisors are found
        return (count == 4) ? sum : 0;
    }
};
