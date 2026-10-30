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
    int good_count = 0;
public:
    void dfs(TreeNode* root, int max) {
        if(!root) return;

        if(root->val >= max) {
            good_count++;
            max = root->val;
        }

        dfs(root->left, max);
        dfs(root->right, max);
        
    }
    int goodNodes(TreeNode* root) {
        // Perform a DFS, as you traverse, store a maximum value seen thus far. 
        // If the current node is smaller than max, mark it as bad.
        // If the current node is larger, increment good counter and set new max.
        
        int max = root->val;
        dfs(root, max);
        return good_count;
    }
};
