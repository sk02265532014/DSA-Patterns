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

// Problem: Construct Binary Tree from Preorder and Inorder Traversal
// Pattern: Binary Tree Construction using Traversals
// Key Idea:
// - Preorder traversal gives the root of the tree/subtree
// - Inorder traversal splits left and right subtrees
// - Use a hashmap to get inorder index in O(1) time
// Time Complexity: O(n)
// Space Complexity: O(n)

class Solution {
public:
    unordered_map<int, int> indexMap;

    // Helper function to build the tree recursively
    TreeNode* build(vector<int>& preorder, int start, int end, int& idx) {
        if (start > end) return nullptr;

        // Create root node using current preorder index
        TreeNode* root = new TreeNode(preorder[idx++]);

        // Find root position in inorder traversal
        int pos = indexMap[root->val];

        // Recursively build left and right subtrees
        root->left = build(preorder, start, pos - 1, idx);
        root->right = build(preorder, pos + 1, end, idx);

        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = inorder.size();

        // Map each value to its index in inorder traversal
        for (int i = 0; i < n; i++) {
            indexMap[inorder[i]] = i;
        }

        int idx = 0; // preorder index
        return build(preorder, 0, n - 1, idx);
    }
};
