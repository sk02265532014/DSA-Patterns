/**
 * Problem: Sum of Root To Leaf Binary Numbers
 * Approach: DFS (Preorder Traversal)
 *
 * Idea:
 * Each root-to-leaf path represents a binary number.
 * While traversing the tree, we build the binary number
 * using the formula:
 *
 *      current_value = current_value * 2 + node->val
 *
 * When we reach a leaf node, we return the computed value.
 * The final answer is the sum of all root-to-leaf binary numbers.
 *
 * Time Complexity: O(N)
 *      - Each node is visited exactly once.
 *
 * Space Complexity: O(H)
 *      - Recursion stack height (H = height of tree).
 */

class Solution {
public:
    int sumRootToLeaf(TreeNode* root) {
        // Start DFS with initial binary value = 0
        return dfs(root, 0);
    }

private:
    int dfs(TreeNode* root, int curr) {
        // Base case: if node is null, contribute 0
        if (!root) 
            return 0;

        // Update current binary number
        // Shift left (multiply by 2) and add current node's value
        curr = curr * 2 + root->val;

        // If leaf node, return the computed binary number
        if (!root->left && !root->right) 
            return curr;

        // Recur for left and right subtree
        // Sum of both subtrees gives total result
        return dfs(root->left, curr) + dfs(root->right, curr);
    }
};
