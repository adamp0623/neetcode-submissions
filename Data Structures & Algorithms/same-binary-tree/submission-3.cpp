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

 // If the values are the same, its a match
 // If they both have a left/right child, its a match
 // If they both DONT have a left/right child, its a match
 // If one has a left/right and the other doesnt, not a match.

 // Perform a recursive DFS, checking values and structure as you go.
 // BaseCase: If p and q is NULL, return true. If p and q exist, return true
 //           If p 

class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(!p && !q) return true;
        if(!p && q || p && !q) return false;
        
        return (isSameTree(p->left, q->left) && 
                isSameTree(p->right, q->right) && p->val == q->val);
    }
};
