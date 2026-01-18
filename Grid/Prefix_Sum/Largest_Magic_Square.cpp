// Problem: Largest Magic Square
// Pattern: 2D Prefix Sum + Brute Force Optimization
//
// Key Idea:
// - Precompute row and column prefix sums
// - Try square sizes from large to small
// - Check:
//   1. All row sums
//   2. All column sums
//   3. Both diagonals
//
// Time Complexity: O(min(m,n)^3)
// Space Complexity: O(m*n)

class Solution {
public:
    int largestMagicSquare(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> row(m, vector<int>(n + 1, 0));
        vector<vector<int>> col(m + 1, vector<int>(n, 0));

        // Build prefix sums
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                row[i][j + 1] = row[i][j] + grid[i][j];
                col[i + 1][j] = col[i][j] + grid[i][j];
            }
        }

        int maxK = min(m, n);

        // Try largest square first
        for (int k = maxK; k >= 2; k--) {
            for (int i = 0; i + k <= m; i++) {
                for (int j = 0; j + k <= n; j++) {

                    int target = row[i][j + k] - row[i][j];
                    bool ok = true;

                    // Check all rows
                    for (int r = i; r < i + k; r++) {
                        if (row[r][j + k] - row[r][j] != target) {
                            ok = false;
                            break;
                        }
                    }

                    // Check all columns
                    for (int c = j; c < j + k && ok; c++) {
                        if (col[i + k][c] - col[i][c] != target) {
                            ok = false;
                            break;
                        }
                    }

                    // Check diagonals
                    int d1 = 0, d2 = 0;
                    for (int t = 0; t < k; t++) {
                        d1 += grid[i + t][j + t];
                        d2 += grid[i + t][j + k - 1 - t];
                    }

                    if (ok && d1 == target && d2 == target)
                        return k;
                }
            }
        }
        return 1;
    }
};
