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

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        // Could maybe do it level by level? Save each level with a BFS, add it to a string? 
        if(!root) return "#";
        string res = "";
        queue<TreeNode*> queue;
        queue.push(root);
        while(!queue.empty()) {
            int lvl_size = queue.size();
            for(int i = 0; i < lvl_size; i++) {
                TreeNode* node = queue.front();
                queue.pop();
                if(!node) res += "#,";
                else res += to_string(node->val) + ",";
                if(node) queue.push(node->left);
                if(node) queue.push(node->right);
            }
        }
        cout<<res<<endl;
        return res;
    }

        // To deserialize, might be harder to do if its constructed level by level.
        // You know the size of the tree. Maybe, for every node in each level, assign its children
        // using the level below. 
        // Keep a counter of how big each level should be. 
     TreeNode* deserialize(string data) {
        stringstream ss(data);
        string val;
        getline(ss, val, ',');
        if (val == "#") return nullptr;
        TreeNode* root = new TreeNode(stoi(val));
        queue<TreeNode*> queue;
        queue.push(root);

        while (getline(ss, val, ',')) {
            TreeNode* node = queue.front();
            queue.pop();
            if (val != "#") {
                node->left = new TreeNode(stoi(val));
                queue.push(node->left);
            }
            getline(ss, val, ',');
            if (val != "#") {
                node->right = new TreeNode(stoi(val));
                queue.push(node->right);
            }
        }
        return root;
    }
};
