class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        // Multiple souce BFS.
        // Each minute is equivalent to each depth level that the BFS explores
        // Keep note of how many fresh fruit there are, and the locations
        // of the rotten fruit in the first pass.
        // If a fresh fruit is found in the BFS, decrement the fresh fruit counter.
        // When the number of fresh fruit goes to zero, break and return the depth level.
        // If the BFS concludes and fresh fruit are not zero, return -1.

        // When exploring, only explore nodes that are fresh fruit, skip if its 
        // already rotten

        int num_fresh = 0;
        queue<pair<int,int>> q;
        for(int i = 0; i < grid.size(); i++) {
            for(int j = 0; j < grid[0].size(); j++) {
                if(grid[i][j] == 1) num_fresh++;
                else if(grid[i][j] == 2) q.push({i,j});
            }
        }
        if(num_fresh == 0) return 0;
        //cout << num_fresh << endl;

        int mins_elapsed = 0;
        while(!q.empty()) {
            int q_size = q.size();
            mins_elapsed++;
            for(int i = 0; i < q_size; i++) {
                auto pos = q.front();
                q.pop();

                vector<pair<int,int>> dirs = {{1, 0}, {-1, 0}, {0,1}, {0,-1}};
                for(auto dir:dirs) {
                    int r = pos.first + dir.first;
                    int c = pos.second + dir.second;
                    if(r < 0 || c < 0 || r >= grid.size() || c >= grid[0].size()) continue;
                    if(grid[r][c] == 0 || grid[r][c] == 2) continue;

                    // This neighboring node is rotten. Infect it, add it to the queue.
                    num_fresh--;
                    // Forgot to mark it rotten!
                    grid[r][c] = 2;
                    q.push({r,c});

                    if(num_fresh == 0) return mins_elapsed;
                }
            }
        }

        return -1;
        //else return mins_elapsed;
    }
};
