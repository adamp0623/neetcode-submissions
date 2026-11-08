class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        // Create a copy of the grid.
        // Iterate across the grid. When you encounter a "1", perform a BFS in horiz/ver 
        // directions where every visited node that is a 1 gets flipped to a zero.
        // Count up the number of times you do this. That is the number of islands.

        vector<vector<char>> visited = grid;
        vector<pair<int,int>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        int n_islands = 0;

        for(int i = 0; i < grid.size(); i++) {
            for(int j = 0; j < grid[0].size(); j++) {

                if(visited[i][j] == '0') continue;
                n_islands++;
                // Perform BFS to clear out "1s" that also belong to this island.

                queue<pair<int,int>> nodes;
                nodes.push({i,j});
                visited[i][j] = '0';
                while(!nodes.empty()) {
                    auto node = nodes.front();
                    nodes.pop();

                    //visited[node.first][node.second] = '0';
                    
                    for(auto dir:dirs) {
                        int r = node.first + dir.first;
                        int c = node.second + dir.second;
                        if(r == grid.size() || r < 0 || c == grid[0].size() || c < 0) continue;
                        if(visited[r][c] == '1') {
                            nodes.push({r,c});
                            visited[r][c] = '0';
                        }
                    }
                }
            }
        }
        return n_islands;
    }
};
