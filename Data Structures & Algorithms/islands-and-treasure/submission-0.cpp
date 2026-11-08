class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        // Since we are finding a shortest distance, BFS will garuntee 
        // this. Do a BFS until a treasure chest is found.
        // We need to initialize a BFS at every INF cell.
        // Or we can do a BFS at every chest location, and mark the INF
        // cells with distance. If you visit a land location that already
        // has a location with it, take the min. 
        //   [2147483647,-1,        0,              2147483647],
        //   [2147483647,2147483647,2147483647,     -1],
        //   [2147483647,-1,        2147483647,     -1],
        //   [0,         -1,        2147483647,     2147483647]

        for(int i = 0; i < grid.size(); i++) {
            for(int j = 0; j < grid[0].size(); j++) {
                if(grid[i][j] != 0) continue;

                queue<pair<int,int>> q;
                q.push({i,j});
                int d = 0; // Distance
                while(!q.empty()) {
                    int q_len = q.size();
                    d++;
                    for(int k = 0; k < q_len; k++) {
                        auto pos = q.front();
                        q.pop();
                        vector<pair<int,int>> dirs = {{1,0}, {-1,0}, {0, 1}, {0,-1}};
                        // We need to explore in every direction
                        for(auto dir:dirs) {
                            int r = pos.first + dir.first;
                            int c = pos.second + dir.second;

                            // Skip this dir if its out of bounds, or is a water
                            if(r < 0 || c < 0 || r >= grid.size() || c >= grid[0].size() ||  grid[r][c] == -1) continue;
                            // If its not INF, ie, its a chest(0) or land thats been assigned a distance already:
                            // Take the minimum, dont add that node to the q. If its a chest, it will stay 0.
                            if(d < grid[r][c]) {
                                grid[r][c] = d;
                                q.push({r,c});
                            }
                        
                        }
                    }
                }
            }
        }

        return;
    }
};
