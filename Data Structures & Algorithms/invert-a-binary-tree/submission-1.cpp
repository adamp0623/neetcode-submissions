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
        // Iterative DFS approach
        // Keep a stack of unexplored nodes. 
        // Everytime we work on a node, we swap the children of that node.
        if(!root) return nullptr;

        vector<TreeNode*> stack;
        // Add the root.
        stack.push_back(root);

        while(!stack.empty()) {
            TreeNode* cur_node = stack.back();
            stack.pop_back();
            auto temp = cur_node->left;
            cur_node->left = cur_node->right;
            cur_node->right = temp;

            // If the children are not nullptr, add them to the stack.
            if(cur_node->left) stack.push_back(cur_node->left);
            if(cur_node->right) stack.push_back(cur_node->right);

        }
        return root;
    }
};
