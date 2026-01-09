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

// Problem: Lowest Common Ancestor of Deepest Leaves
// Pattern: Binary Tree DFS (Bottom-Up)
// Key Idea:
// - For each node, return:
//     1) the subtree root that contains all deepest nodes
//     2) the depth of the deepest node in that subtree
//
// - If left and right depths are equal, current node is the answer
// - Otherwise, propagate the deeper subtree upward
//
// Time Complexity: O(n)
// Space Complexity: O(h) (recursion stack)

class Solution {
public:
    // Returns {node_with_all_deepest, depth}
    pair<TreeNode*, int> dfs(TreeNode* root) {
        if (!root)
            return {nullptr, -1};

        auto left = dfs(root->left);
        auto right = dfs(root->right);

        // If both sides have same depth, current node is LCA
        if (left.second == right.second)
            return {root, left.second + 1};

        // Otherwise propagate the deeper side
        if (left.second > right.second)
            return {left.first, left.second + 1};
        else
            return {right.first, right.second + 1};
    }

    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        return dfs(root).first;
    }
};
