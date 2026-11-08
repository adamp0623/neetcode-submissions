/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        // Need to do either BFS or DFS, where the nodes to explore
        // exist as a vector of pointers to the next node to visit.
        // Do BFS, so that each level we discover (level is a new list of nodes  
        // to explore added to the queue) can be assigned a value
        // ex: [[2],[1,3],[2]]
        // Add Node 1 to queue, check the size of the queue, create a 
        // copy of this node to add to result and include its neighbours.
        // Then push every neighbour of Node 1 on to the queue [2]
        // Process

        // We need to return the first node in the graph.
        // This node should point to other nodes, which point to other nodes.
        // Im not sure how to reconstruct this result as I traverse...
        if(!node) return nullptr;
        Node* res = new Node(node->val);

        unordered_map<Node*, Node*> clones;
        queue<Node*> nodes;
        nodes.push(node);

        clones[node] = res;
        
        while(!nodes.empty()) {
            auto node = nodes.front();
            nodes.pop();

            for(auto neighbor:node->neighbors) {
                if(clones.find(neighbor) == clones.end()) {
                    Node* clone = new Node(neighbor->val);
                    clones[neighbor] = clone;
                    nodes.push(neighbor);
                }
                clones[node]->neighbors.push_back(clones[neighbor]);
            }

        }

        return res;

    }
};
