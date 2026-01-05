// Problem: Find the Pivot Integer
// Pattern: Math + Prefix Sum Observation
// Key Idea:
// Let total = n * (n + 1) / 2
// We need x such that:
//   1 + 2 + ... + x = x + (x + 1) + ... + n
// This simplifies to:
//   x^2 = total
// So x exists if and only if total is a perfect square
// Time Complexity: O(1)
// Space Complexity: O(1)

class Solution {
public:
    int pivotInteger(int n) {
        int total = n * (n + 1) / 2;
        int root = sqrt(total);

        // Check if total is a perfect square
        return (root * root == total) ? root : -1;
    }
};
