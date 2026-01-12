// Problem: Factorial Trailing Zeroes
// Pattern: Number Theory - Counting Factors
//
// Key Idea:
// - Trailing zeroes are created by factors of 10
// - 10 = 2 × 5
// - There are more factors of 2 than 5 in factorials
// - So, count how many times 5 appears as a factor
//
// Count = n/5 + n/25 + n/125 + ...
//
// Time Complexity: O(log n)
// Space Complexity: O(1)

class Solution {
public:
    int trailingZeroes(int n) {
        int count = 0;

        while (n > 0) {
            n /= 5;
            count += n;
        }

        return count;
    }
};
