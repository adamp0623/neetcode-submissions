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
    // For example, for p = 3, q = 4.
    // Store the values compared to get there.
    // for P: 5, 3,  
    // for Q: 5, 3,
    // With these two lists, need to take from the top until the values match.
    // When to take??
    // Take from the larger list, until levels match.
    // Then take 

    // Say 
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // First need to find each value of p, and q, and store the values in a stack

        vector<TreeNode*> p_explored;
        vector<TreeNode*> q_explored;
        
        // Find it for p
        auto node = root;
        p_explored.push_back(node);
        while(p->val != node->val) {
            if(p->val < node->val) node = node->left;
            else if(p->val > node->val) node = node->right;
            p_explored.push_back(node);
        }

        // Find it for q
        node = root;
        q_explored.push_back(node);
        while(q->val != node->val) {
            if(q->val < node->val) node = node->left;
            else if(q->val > node->val) node = node->right;
            q_explored.push_back(node);
        }

        // Pop until they have the same number 
        while(p_explored.size() != q_explored.size()) {
            if(p_explored.size() > q_explored.size()) p_explored.pop_back();
            else q_explored.pop_back();
        }
        // Now their sizes equal. Pop the values until they equal
        while(p_explored.size() != 0) {
            if(p_explored.back()->val == q_explored.back()->val) return p_explored.back();
            p_explored.pop_back();
            q_explored.pop_back();
        }
        return NULL;
    }
};
