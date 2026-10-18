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
public:
    TreeNode* invertTree(TreeNode* root) {
        // Tree node has a left and right child. 
        // We need to swap every leaf of the tree. /
        // Maybe go down the tree until there are no chlidren, and then swap the children
        // once thats true.

        if(!root) return nullptr;
        
        queue<TreeNode*> nodes;
        nodes.push(root);

        while(!nodes.empty()) {
            TreeNode* cur_node = nodes.front();
            nodes.pop();
            auto temp = cur_node->left;
            cur_node->left = cur_node->right;
            cur_node->right = temp;

            if(cur_node->left) nodes.push(cur_node->left);
            if(cur_node->right) nodes.push(cur_node->right);

        }
        return root;
        
    }
};
