// Problem: Maximum Dot Product of Two Subsequences
// Pattern: Dynamic Programming on Subsequences
// Key Idea:
// dp[i][j] = maximum dot product using first i elements of nums1
//            and first j elements of nums2
//
// At each step, we have three choices:
// 1. Take current pair: nums1[i-1] * nums2[j-1]
//    (optionally add dp[i-1][j-1] if it is positive)
// 2. Skip element from nums1
// 3. Skip element from nums2
//
// Using max(0, dp[i-1][j-1]) ensures non-empty subsequence handling
//
// Time Complexity: O(m * n)
// Space Complexity: O(m * n)

class Solution {
public:
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();

        // dp[i][j] stores the max dot product using
        // first i elements of nums1 and first j elements of nums2
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, INT_MIN));

        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {

                // Option 1: Take current pair
                int take = nums1[i - 1] * nums2[j - 1]
                           + max(0, dp[i - 1][j - 1]);

                // Option 2: Skip element from nums1
                int skip1 = dp[i - 1][j];

                // Option 3: Skip element from nums2
                int skip2 = dp[i][j - 1];

                // Choose the best option
                dp[i][j] = max({take, skip1, skip2});
            }
        }

        return dp[m][n];
    }
};
