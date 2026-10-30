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
    // If you do an in-order traversal, the list should be sorted in ascending order.
    // Everytime you process a node check that its increasing. If not, return false.
    vector<int> explored_vals;

public:
    void inOrderTraversal(TreeNode* root) {
        if(!root) return;

        // Explore left
        inOrderTraversal(root->left);
        explored_vals.push_back(root->val);
        inOrderTraversal(root->right);
        
    }

    bool isValidBST(TreeNode* root) {
        inOrderTraversal(root);
        if(explored_vals.size() == 1) return true;

        for(int i = 1; i < explored_vals.size(); i++) {
            if(explored_vals[i] <= explored_vals[i-1]) return false;
        }
        return true;
    }
};
