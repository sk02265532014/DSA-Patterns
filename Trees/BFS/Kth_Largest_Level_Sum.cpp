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

// Problem: Kth Largest Level Sum in a Binary Tree
// Pattern: Binary Tree - Level Order Traversal (BFS)
// Key Idea:
// - Traverse the tree level by level using a queue
// - Compute sum of each level
// - Sort level sums in descending order
// - Return the k-th largest sum
// Time Complexity: O(n + L log L), where L = number of levels
// Space Complexity: O(n)

class Solution {
public:
    long long kthLargestLevelSum(TreeNode* root, int k) {
        vector<long long> levelSum;
        queue<TreeNode*> q;
        q.push(root);

        // Level order traversal
        while (!q.empty()) {
            int n = q.size();
            long long sum = 0;

            for (int i = 0; i < n; i++) {
                TreeNode* curr = q.front();
                q.pop();

                sum += curr->val;

                if (curr->left) q.push(curr->left);
                if (curr->right) q.push(curr->right);
            }

            levelSum.push_back(sum);
        }

        // If k is greater than number of levels
        if (levelSum.size() < k) return -1;

        // Sort level sums in descending order
        sort(levelSum.begin(), levelSum.end(), greater<long long>());

        return levelSum[k - 1];
    }
};
