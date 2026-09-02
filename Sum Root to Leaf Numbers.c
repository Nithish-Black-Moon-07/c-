/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

int dfs(struct TreeNode* node, int currentSum) {
    // Base case: if the node is empty, it contributes 0 to the sum
    if (node == NULL) {
        return 0;
    }
    
    // Update the running number for the current path
    currentSum = currentSum * 10 + node->val;
    
    // If we reach a leaf node, return the completed path number
    if (node->left == NULL && node->right == NULL) {
        return currentSum;
    }
    
    // Recurse for left and right subtrees and sum their results
    return dfs(node->left, currentSum) + dfs(node->right, currentSum);
}

int sumNumbers(struct TreeNode* root) {
    return dfs(root, 0);
}
