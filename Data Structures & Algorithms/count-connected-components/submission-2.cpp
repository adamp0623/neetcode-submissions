class Solution {
    unordered_map<int,vector<int>> mapping;
    unordered_set<int> visited;
public:
    void dfs(int node, int parent) {
        if(visited.find(node) != visited.end()) return;
        if(mapping[node].empty()) {
            return;
        }
        visited.insert(node);
        cout << parent << endl;
        cout << node << endl;
        for(auto nei:mapping[node]) {
            if(nei == parent) continue;
            dfs(nei, node);
        }

        mapping[node].clear();
        return;

    }
    int countComponents(int n, vector<vector<int>>& edges) {
        // You have edge connections. 
        // Do a traversal on one of the edges. When a node is explored from that starting 
        // point, remove it from the list of starting points. Every traversal should raise a counter
        // check if there are any nodes to explore left, if yes, keep 
        // looking for more sets of connected components. If not, return the counter.

        // Need to get around one problem. Cycles can create infinite loops.
        // Make sure to return if a cycle is detected. 

        for(int i = 0; i < edges.size(); i++) {
            mapping[edges[i][0]].push_back(edges[i][1]);
            mapping[edges[i][1]].push_back(edges[i][0]);
        }

        int connected_count = 0;
        // You can have nodes on th
        for(int i = 0; i < n; i++) {
            if(visited.find(i) != visited.end()) continue;
            dfs(i, -1);
            connected_count++;
        }
        return connected_count;
    }
};
