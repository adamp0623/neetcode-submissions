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
    vector<int> sorted;
public:
    void inOrder(TreeNode* root) {
        if(!root) return;

        inOrder(root->left);
        sorted.push_back(root->val);
        inOrder(root->right);
    }
    int kthSmallest(TreeNode* root, int k) {
        // 1th smallest value is just the minimum value.
        // The value k is limited by the number of nodes in the tree.
        // If you do an in-order traversal of a BST, the resulting list should
        // be sorted in ascending order, then you can find the kth smallest
        // easily, by indexing the n - k element.
        // That would be a O(n) time, O(n), solution. 
        inOrder(root);
        // Say, we want 1th smallest of [1,2,3,4]
        // Take k - 1 value of this list. If you want 4th smallest
        return sorted[k - 1];
    }
};
