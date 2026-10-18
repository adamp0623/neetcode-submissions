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
    int maxDepth(TreeNode* root) {
        // Do a DFS, and keep a counter. everytime you explore a new
        // layer of the tree, you can increase the counter. When 
        // a null is reached, you save that as a candidate.

        if(!root) return 0;

        vector<pair<TreeNode*, int>> stack;
        stack.push_back({root,1});

        int max_depth = 0;
        
        while(!stack.empty()) {
            auto cur_node = stack.back();
            stack.pop_back();

            // Update the max depth with the depth level of what we are exploring.
            max_depth = max(cur_node.second, max_depth);

            // If the child exists, add it to the stack and assign an increased depth by 1
            if(cur_node.first->left) stack.push_back({cur_node.first->left, cur_node.second+1});
            if(cur_node.first->right) stack.push_back({cur_node.first->right, cur_node.second+1});
        }

        return max_depth;
    }
};
