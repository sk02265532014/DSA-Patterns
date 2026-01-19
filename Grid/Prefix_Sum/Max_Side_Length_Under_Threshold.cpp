// Problem: Maximum Side Length of a Square with Sum <= Threshold
// Pattern: Grid + Prefix Sum + Binary Search on Answer
//
// Key Idea:
// - Use 2D prefix sum to compute submatrix sums in O(1)
// - Binary search on the side length of the square
// - For each candidate size, check if any square satisfies the threshold
//
// Time Complexity:
// - Prefix sum: O(m * n)
// - Binary search: O(log(min(m, n)) * m * n)
//
// Space Complexity: O(m * n)

class Solution {
public:
    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        int m = mat.size(), n = mat[0].size();

        // 2D prefix sum array
        vector<vector<int>> prefix(m + 1, vector<int>(n + 1, 0));

        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                prefix[i][j] = mat[i - 1][j - 1]
                             + prefix[i - 1][j]
                             + prefix[i][j - 1]
                             - prefix[i - 1][j - 1];
            }
        }

        int low = 1, high = min(m, n), ans = 0;

        // Binary search on side length
        while (low <= high) {
            int mid = (low + high) / 2;
            bool possible = false;

            // Check all squares of side length = mid
            for (int i = 0; i + mid <= m && !possible; i++) {
                for (int j = 0; j + mid <= n; j++) {
                    int sum = prefix[i + mid][j + mid]
                            - prefix[i][j + mid]
                            - prefix[i + mid][j]
                            + prefix[i][j];

                    if (sum <= threshold) {
                        possible = true;
                        break;
                    }
                }
            }

            if (possible) {
                ans = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        return ans;
    }
};
