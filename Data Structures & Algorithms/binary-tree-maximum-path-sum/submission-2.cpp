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
#include <cmath>
class Solution {
    int max_path_sum;
public:
    int bestSum(TreeNode* root) {
        if(!root) return 0;

        int left_sum = bestSum(root->left);
        int right_sum = bestSum(root->right);
        max_path_sum = max(max_path_sum, root->val + left_sum + right_sum);

        if(left_sum < 0 && right_sum < 0){
            max_path_sum = max(max_path_sum, root->val);
            return root->val;
        }
        else if(left_sum > right_sum) {
            max_path_sum = max(max_path_sum, left_sum + root->val);
            return left_sum + root->val;
        } 
        else{
            max_path_sum = max(max_path_sum, right_sum + root->val);
            return right_sum + root->val;
        }
    }
    int maxPathSum(TreeNode* root) {
        // Bruteforce: compute every possible path,
        // add up those values along the path, and take the max

        // Think about a simple case first, where if its just root and children,
        // all possible combinations are: root to left, root to right, or
        // left -> root -> right

        // Each root should contain information about path sum 
        // of going in each direction. For every node, save best option of going
        // either to right child or left child, and save the max value
        // going through the root. 
        max_path_sum = root->val;
        bestSum(root);
        return max_path_sum;

    }
};
