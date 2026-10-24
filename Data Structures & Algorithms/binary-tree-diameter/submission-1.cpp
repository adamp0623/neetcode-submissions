/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
    int maxDiameter = 0;

public:
    // Recurse down to the leaf, until the child is null.
    int dfs(TreeNode*root) {
        if(!root) return 0;

        int left_height = dfs(root->left);
        int right_height = dfs(root->right);
        maxDiameter = max(maxDiameter, left_height+right_height);

        return 1 + max(left_height, right_height);

    }

    int diameterOfBinaryTree(TreeNode* root) {
        // Height of the longest branch on the left and on the right.
        dfs(root);
        return maxDiameter;
        
    }
};
