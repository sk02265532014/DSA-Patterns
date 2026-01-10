// Problem: Longest Common Subsequence
// Pattern: Subsequence Dynamic Programming (Base Template)
//
// Key Idea:
// dp[i][j] = length of LCS between
//            text1[0..i-1] and text2[0..j-1]
//
// This is the foundational DP that many string DP problems build upon.
//
// Time Complexity: O(m * n)
// Space Complexity: O(m * n)

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.size();
        int n = text2.size();

        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (text1[i - 1] == text2[j - 1]) {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                } else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        return dp[m][n];
    }
};
