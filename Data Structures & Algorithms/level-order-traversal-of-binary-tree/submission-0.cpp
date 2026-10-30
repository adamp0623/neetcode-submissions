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
    vector<vector<int>> levelOrder(TreeNode* root) {
        // Can you just do a breadth first search, and save each level?
        // For every level n, there should be at most 2^n nodes in that level.
        // If you do a BFS, populate a queue with the nodes to explore.
        // If the queue is larger than the respective level, add each node to its level.

        // [2,3]
        // Is size greater than or equal to 2^(1)? Yes. Add it
        if(!root) return {};
        queue<pair<TreeNode*, int>> queue;
        vector<vector<int>> res;

        vector<int> level;
        int cur_level = 1;

        queue.push({root,1});
        while(!queue.empty()) {
            auto node = queue.front();
            queue.pop();

            if(cur_level < node.second) {
                // Exploring a new level, push old and clear it.
                res.push_back(level);
                level.clear();
                cur_level++;
            }
            level.push_back(node.first->val);

            if(node.first->left) queue.push({node.first->left, node.second + 1});
            if(node.first->right) queue.push({node.first->right, node.second + 1});
        }
        res.push_back(level);
        // Then loop across discovered nodes, adding them to the outputs.

        return res;
    }
};
