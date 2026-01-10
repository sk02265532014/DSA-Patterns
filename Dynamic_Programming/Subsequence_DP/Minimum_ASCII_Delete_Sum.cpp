// Problem: Minimum ASCII Delete Sum for Two Strings
// Pattern: Dynamic Programming on Strings (LCS Variant)
//
// Key Idea:
// - Instead of finding LCS length, compute the maximum ASCII sum
//   of the common subsequence.
// - Total delete cost = sum(s1) + sum(s2) - 2 * common_ascii_sum
//
// dp[i][j] = maximum ASCII sum of common subsequence
//            between s1[0..i-1] and s2[0..j-1]
//
// Time Complexity: O(m * n)
// Space Complexity: O(m * n)

class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        int m = s1.size();
        int n = s2.size();

        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

        // Build DP table
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (s1[i - 1] == s2[j - 1]) {
                    // Add ASCII value if characters match
                    dp[i][j] = int(s1[i - 1]) + dp[i - 1][j - 1];
                } else {
                    // Skip one character
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }

        // Total ASCII sum of both strings
        int sum1 = 0, sum2 = 0;
        for (char c : s1) sum1 += int(c);
        for (char c : s2) sum2 += int(c);

        // Minimum delete sum
        return sum1 + sum2 - 2 * dp[m][n];
    }
};
