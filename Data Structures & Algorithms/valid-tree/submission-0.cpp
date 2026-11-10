class Solution {
    unordered_map<int, vector<int>> mapping;
    unordered_set<int> visited;

public:
    // Need to do a DFS with cycle detection
    // If you try to traverse the tree from every node, if its a valid tree,
    // you would be able to reach every node in the tree.
    // If there are no cycles, and you are able to reach every node in the tree at least
    // once from connections, then you can return true.

    // You need to keep track of explored nodes in a traversal
    // You need to keep track of the nodes you are currently visiting in a traversal.
    // If you revisit the same node you already visited, that indicates a cycle.
    
    // This is an undirected graph. One node pair [i,j] represents an edge where
    // you can travel in either direction. Only haveing a mapping of i: j shows where
    // you can go if you start at i (j), but if you start at j, you dont have information
    // about where to go, even if you could go to i.

    // In that second example, if you only consider revisiting ancestors as a cycle, you
    // wont find the 1 - 2 - 3 cycle. You could visit 0 -> 1: [2,3] -> 2: [3], then when
    // call at node 2 finishes, it removes 3 from being in the visiting set.

    // Now with both directions represented, once you go from 0 -> 1, 1 -> 0 now exists.
    // Maintain a stack of most recently visited nodes. That is the parent. If the node
    // you visit is in the visiting set and is not at the top of the stack, that is a cycle

    bool dfs(int node, int parent) {
        // This is a cycle.
        if(visited.find(node) != visited.end()) {
            return false;
        }

        visited.insert(node);
        //cout << node << endl;
        for(auto nei:mapping[node]) {
            if(nei == parent) continue;
            if(!dfs(nei, node)) return false;
        }
        //visited.erase(node);

        return true;

        
    }

    

    bool validTree(int n, vector<vector<int>>& edges) {
        // A tree is where each node has (or doesnt have) children,
        // and the children only connect to its children or parent.
        // If a child connects to an ancestor that is not its parent, 
        // then its invalid, or if a child connects to another child 
        // of the same parent. Essentially neeed to detect cycles

        // First need to create a map.
        // If edges are [[0,1]]
        // This will create 0: [1] 1: [0]
        // The map now includes both directions of travel along an edge.

        for(int i = 0; i < edges.size(); i++) {
            mapping[edges[i][0]].push_back(edges[i][1]);
            mapping[edges[i][1]].push_back(edges[i][0]);
        }

        if(!dfs(0, -1)) return false;
        if(visited.size() == n) return true;
        else return false;

    }
};
