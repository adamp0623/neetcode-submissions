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
    bool height_balanced = true;

    int dfs(TreeNode* root) {
        if(!root) return 0;

        int left_height = dfs(root->left);
        int right_height = dfs(root->right);

        if(abs(left_height - right_height) > 1) height_balanced = false;

        return 1 + max(left_height, right_height);
    }
public:
    bool isBalanced(TreeNode* root) {
        // At each node, need to check if height of left and right subtrees differ by 
        // more than one.
        dfs(root);
        return height_balanced;
        
    }
};
