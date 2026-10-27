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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        // For two trees to be the same, they need have the same values at 
        // matching positions. They need to have the same number of nodes, 
        // and same structure. 
        // Why cant you just iterate across the list of nodes, and just check?
        // Just do a BFS, and check that they match.
        if(!p && !q) return true;
        

        queue<TreeNode*> queue_p;
        queue<TreeNode*> queue_q;
        if(p) queue_p.push(p);
        if(q) queue_q.push(q);

        while(!queue_p.empty() && !queue_q.empty()) {
            auto p_node = queue_p.front();
            auto q_node = queue_q.front();
            queue_p.pop();
            queue_q.pop();

            // Need to check if the popped nodes match values.
            if(p_node->val != q_node->val) return false;

            if(p_node->left && q_node->left) {
                queue_p.push(p_node->left);
                queue_q.push(q_node->left);
            }
            else if(!p_node->left && !q_node->left) {}
            else return false;
            
            if(p_node->right && q_node->right) {
                queue_p.push(p_node->right);
                queue_q.push(q_node->right);
            }
            else if(!p_node->right && !q_node->right) {}
            else return false;

        }

        if(!queue_p.empty() || !queue_q.empty()) return false;
        return true;

    }
};
