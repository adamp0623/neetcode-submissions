class Solution {
public:
    void dfs(vector<vector<int>>& visited, int r, int c, int& area) {
        if(r >= visited.size() || c >= visited[0].size() || r < 0 || c < 0 || visited[r][c] == 0) {
            return;
        }

        visited[r][c] = 0;
        area++;

        dfs(visited, r + 1, c, area);
        dfs(visited, r - 1, c, area);
        dfs(visited, r, c + 1, area);
        dfs(visited, r, c - 1, area);

        return;

    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int max_area = 0;
        vector<vector<int>> visited = grid;

        for(int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                
                if(visited[i][j] == 0) continue;
                int area = 0;
                dfs(visited, i, j, area);
                max_area = max(max_area, area);
                
            }
        }
        return max_area;
    }
};
