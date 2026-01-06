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

// Problem: Maximum Level Sum of a Binary Tree
// Pattern: Binary Tree - Level Order Traversal (BFS)
// Key Idea:
// - Traverse the tree level by level using a queue
// - Compute sum of each level
// - Track the level having maximum sum
// Time Complexity: O(n)
// Space Complexity: O(n)

class Solution {
public:
    int maxLevelSum(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);

        int maxSum = INT_MIN;
        int ans = 0;
        int level = 0;

        // Perform level order traversal
        while (!q.empty()) {
            int sum = 0;
            level++;
            int n = q.size();

            // Process all nodes at the current level
            for (int i = 0; i < n; i++) {
                TreeNode* curr = q.front();
                q.pop();

                sum += curr->val;

                if (curr->left) q.push(curr->left);
                if (curr->right) q.push(curr->right);
            }

            // Update maximum sum and corresponding level
            if (sum > maxSum) {
                maxSum = sum;
                ans = level;
            }
        }

        return ans;
    }
};
