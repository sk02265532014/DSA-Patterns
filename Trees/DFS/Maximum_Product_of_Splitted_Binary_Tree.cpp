/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right)
 *         : val(x), left(left), right(right) {}
 * };
 */

// Problem: Maximum Product of Splitted Binary Tree
// Pattern: Binary Tree - DFS with Subtree Sum
// Key Idea:
// 1. Compute total sum of the tree
// 2. For every subtree, calculate:
//      product = subtreeSum * (totalSum - subtreeSum)
// 3. Track the maximum product
// Time Complexity: O(n)
// Space Complexity: O(h) (recursion stack)

class Solution {
public:
    long long total = 0;
    long long maxProductValue = 0;
    int mod = 1e9 + 7;

    int maxProduct(TreeNode* root) {
        // Step 1: compute total sum of the tree
        total = totalSum(root);

        // Step 2: compute subtree sums and update max product
        dfs(root);

        return maxProductValue % mod;
    }

private:
    // Compute total sum of the tree
    long long totalSum(TreeNode* root) {
        if (!root) return 0;
        return root->val + totalSum(root->left) + totalSum(root->right);
    }

    // DFS to compute subtree sums and product
    long long dfs(TreeNode* root) {
        if (!root) return 0;

        long long leftSum = dfs(root->left);
        long long rightSum = dfs(root->right);

        long long subtreeSum = root->val + leftSum + rightSum;

        // Calculate product of current split
        long long product = subtreeSum * (total - subtreeSum);

        // Update maximum product
        maxProductValue = max(maxProductValue, product);

        return subtreeSum;
    }
};
