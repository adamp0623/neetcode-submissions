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
    vector<int> rightSideView(TreeNode* root) {
        // Do a BFS, and at each level, save the value at the top of the queue.
        if(!root) return {};
        vector<int> res;
        queue<TreeNode*> queue;
        queue.push(root);

        while(!queue.empty()) {
            res.push_back(queue.back()->val);

            int levelSize = queue.size();
            for(int i = 0; i < levelSize; i++) {
                auto node = queue.front();
                queue.pop();
                if(node->left) queue.push(node->left);
                if(node->right) queue.push(node->right);
            }

        }
        return res;        
    }
};
