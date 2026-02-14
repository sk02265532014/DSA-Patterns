/*
    Problem: Champagne Tower
    Platform: LeetCode (799)
    Approach: Row-by-row DP simulation

    Time Complexity: O(n^2)
    Space Complexity: O(n)

    Idea:
    - Each glass can hold at most 1 unit.
    - Extra amount overflows equally to two glasses below.
    - Simulate row by row using 1D DP.
*/

class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {

        // Base case: top glass
        if (query_row == 0)
            return min(1.0, (double)poured);

        // dp represents current row
        vector<double> dp(1);
        dp[0] = poured;

        for (int i = 0; i < query_row; i++) {

            // Next row will have i+2 glasses
            vector<double> next(i + 2, 0.0);

            for (int j = 0; j <= i; j++) {

                // Overflow amount
                double overflow = max(0.0, dp[j] - 1.0);

                // Distribute equally
                next[j] += overflow / 2.0;
                next[j + 1] += overflow / 2.0;
            }

            dp = next;
        }

        return min(1.0, dp[query_glass]);
    }
};
