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
    unordered_map<int,int> indices;
    int pre_idx = 0;
public:
    TreeNode* dfs(vector<int>& preorder, int l, int r) {
        if (l>r) return nullptr;
        int root_val = preorder[pre_idx++];
        TreeNode *root = new TreeNode(root_val);
        int mid = indices[root_val];
        root->left = dfs(preorder, l, mid - 1);
        root->right = dfs(preorder, mid + 1, r);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        // Need to recreate the binary tree from preorder and inorder.
        // Preorder is root, left child, right child.
        // Inorder is left child, root, right child. 
        // To build the tree, assign the root, and then its children

        // Maybe construct the tree in the order of which it was traversed.
        // Like maybe simulate a traversal, and assign values to nodes according to that order.
        for(int i = 0; i < preorder.size(); i++) {
            indices[inorder[i]] = i;
        }
        return dfs(preorder, 0, inorder.size() - 1);




    }
};
