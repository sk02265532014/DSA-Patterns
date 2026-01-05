// Problem: Maximum Matrix Sum
// Pattern: Greedy + Math Observation
// Key Idea:
// - Convert all values to absolute values
// - If count of negative numbers is even → all can be positive
// - If odd → one smallest absolute value must remain negative
// Time Complexity: O(n * m)
// Space Complexity: O(1)
class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        long long sum = 0;
        int smallest = INT_MAX, negative = 0;

        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[0].size(); j++) {

                // Count negative numbers
                if (matrix[i][j] < 0) negative++;

                // Work with absolute values
                int x = abs(matrix[i][j]);
                smallest = min(smallest, x);
                sum += x;
            }
        }

        // If negatives are odd, one smallest value must stay negative
        return (negative % 2) ? sum - 2 * smallest : sum;
    }
};
