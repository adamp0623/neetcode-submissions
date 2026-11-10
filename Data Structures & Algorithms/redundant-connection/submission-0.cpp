class Solution {
    unordered_map<int,vector<int>> mapping;
    unordered_set<int> visited;
    unordered_set<int> cycles;
    int cycle_start;
public:
    bool dfs(int node, int parent) {
        if(visited.find(node) != visited.end()) {
            cycle_start = node;
            return true;
        }

        visited.insert(node);
        for (int nei:mapping[node]) {
            if (nei == parent) continue;
            if(dfs(nei, node)) {
                if(cycle_start != -1) cycles.insert(node);
                if(node == cycle_start) {
                    cycle_start = -1;
                }
                return true;
            }
        }
        return false;
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        // You have a graph, with n nodes, and has n - 1 edges
        // ex A - B - C
        // Another is added, so that edge should create a cycle somewhere.
        // The idea is to find that redundant (cycle creating edge) and remove 
        // it, and if there are multiple redundant edges, just return
        // the latest one in the edges list.

        // It started connected, so you could start from any node, and
        // be able to find the cycle.
        // One less than optimal method is to find every cycle but starting
        // at every node, and adding all the redundant edges to the result.
        // Then you could start from the end of edges and find the first 
        // edge that exists in the cycles edge.

        // Add both directions to the adj list.
        for(int i = 0; i < edges.size(); i++) {
            mapping[edges[i][0]].push_back(edges[i][1]);
            mapping[edges[i][1]].push_back(edges[i][0]);
        }

        cycle_start = -1;
        dfs(1, -1);

        for(int i = edges.size() - 1; i >= 0; i--) {
            int u = edges[i][0];
            int v = edges[i][1];
            if(cycles.find(u) != cycles.end() && cycles.find(v) != cycles.end()) {
                return {u,v};
            }
        }
        return {};

        // Add cyclical edges to a set, but dont stop when a cycle is found.

    }
};
