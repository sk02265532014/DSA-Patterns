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

// Problem: Binary Tree Zigzag Level Order Traversal
// Pattern: Binary Tree - BFS with Direction Control
// Key Idea:
// - Perform level order traversal using a queue
// - Use a direction flag to decide index placement
// - Fill current level values left-to-right or right-to-left
//   without reversing the vector
// Time Complexity: O(n)
// Space Complexity: O(n)

class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if (!root) return ans;

        queue<TreeNode*> q;
        q.push(root);
        bool leftToRight = true;

        while (!q.empty()) {
            int n = q.size();
            vector<int> level(n);

            for (int i = 0; i < n; i++) {
                TreeNode* curr = q.front();
                q.pop();

                // Decide index based on traversal direction
                int index = leftToRight ? i : n - i - 1;
                level[index] = curr->val;

                if (curr->left) q.push(curr->left);
                if (curr->right) q.push(curr->right);
            }

            ans.push_back(level);
            leftToRight = !leftToRight; // toggle direction
        }

        return ans;
    }
};
