// Problem: Delete Operation for Two Strings
// Pattern: String DP (LCS-based Transformation)
//
// Key Idea:
// - Find the Longest Common Subsequence (LCS)
// - Characters not in LCS must be deleted
// - Minimum deletions =
//     len(word1) + len(word2) - 2 * LCS
//
// dp[i][j] = length of LCS between
//            word1[0..i-1] and word2[0..j-1]
//
// Time Complexity: O(m * n)
// Space Complexity: O(m * n)

class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.size();
        int n = word2.size();

        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

        // Compute LCS length
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (word1[i - 1] == word2[j - 1]) {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                } else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }

        // Minimum deletions required
        return m + n - 2 * dp[m][n];
    }
};
