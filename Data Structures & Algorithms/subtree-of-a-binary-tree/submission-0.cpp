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
    // If you call isSameTree on every node, if there is a matching subroot, it will eventually  return true.
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(!p && !q) return true;
        if(!p && q || p && !q) return false;
        
        return (isSameTree(p->left, q->left) && 
                isSameTree(p->right, q->right) && p->val == q->val);
    }

    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        // Perform a recursive DFS using isSubtree, and use isSameTree.
        // In the base case, check if root is NULL. If root is NULL, it cant contain a subtree 
        // matching subRoot. If its not NULL, it might contain a matching subtree

        if(!root) return false;

        // This root might contain a matching subtree. Need to check if this subtree
        // matches the subroot.
        // If it matches, return true.
        // If it doesnt, maybe the children match.
        // Peform isSubtree on the left and right children.
 
        return isSameTree(root, subRoot) || 
               isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
    }
};
