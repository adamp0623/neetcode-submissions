class Solution {
public:
    void dfs(vector<vector<bool>>& visited, const vector<vector<int>>& heights, const vector<vector<bool>>& solution_map, int r, int c, bool& p_found, bool& a_found, int prev_val) {
        // Stop dfs if out of range.
        if(r < 0 || c < 0 || r >= heights.size() || c >= heights[0].size()) return;
        // Also need to check if the current cell value smaller or equal to the previous...
        if(heights[r][c] > prev_val) return;
        if (visited[r][c]) return;
        visited[r][c] = true;

        // Check if current cell is in the solution set already.
        if(solution_map[r][c]) {
            p_found = true;
            a_found = true;
            return;
        }

        // If the current cell is on the pacific edge
        if(r == 0 || c == 0) {
            p_found = true;
        }
        // If the current cell is on the atlantic edge
        if(r == heights.size() - 1 || c == heights[0].size() - 1) a_found = true;

        // If both flags are raised, this search is done.
        if(p_found && a_found) {
            return;
        }

        // Do DFS on all the neighbours. 
        prev_val = heights[r][c];
        dfs(visited, heights, solution_map, r + 1, c, p_found, a_found, prev_val);
        dfs(visited, heights, solution_map, r - 1, c, p_found, a_found, prev_val);
        dfs(visited, heights, solution_map, r, c + 1, p_found, a_found, prev_val);
        dfs(visited, heights, solution_map, r, c - 1, p_found, a_found, prev_val);

        return;


    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        // r = -1, c = -1, is pacific
        // c = # cols + 1, r = # rows + 1
        // Water can only move from one cell to another if its equal or lower.
        // Water can flow into the ocean from cells next to the ocean. 
        // The top right, and bottem left  cells will always be in the solution.
        
        // You can imagine pouring water on to a cell. If that water can flow to
        // both the pacific and the atlantic, That cell is included in the soln.

        // Do a BFS, on every node, only exploring neighbors if they have a value
        // <= the current cell value. Check if an explored node is at the bottom
        // or right side of the grid. If it is, raise a flag. Also check if an 
        // explored node is at the top or right side. Raise a flag.
        // If both flags are raised, stop searching, and include the root node
        // in the solution. 
        
        // I feel this does repeated work. Any search that finds a valid neighbor that
        // already exists in the solution set, you can stop early and mark the root
        // as in the solution set.
        // Use a map, to keep track of valid nodes, for easy O(1) checking

        vector<vector<bool>> solution_map;
        vector<vector<int>> res;
        for(int i = 0; i < heights.size(); i++) {
            vector<bool> row;
            for (int j = 0; j < heights[0].size(); j++) {
                if(i == heights.size() - 1 && j == 0) row.push_back(true);
                else if(i == 0 && j == heights[0].size() - 1) row.push_back(true);
                else row.push_back(false);
            }
            solution_map.push_back(row);
        }

        // Iterate through every value on the grid
        for(int i = 0; i < heights.size(); i++) {
            for (int j = 0; j < heights[0].size(); j++) {
                vector<vector<bool>> visited(
                        heights.size(), vector<bool>(heights[0].size(), false)
                    );
                // Conduct a DFS on the node.
                bool p_found = false;
                bool a_found = false;
                dfs(visited, heights, solution_map, i, j, p_found, a_found, 1001);
                if(p_found && a_found) {
                    solution_map[i][j] = true;
                    res.push_back({i,j});
                }
            }
        }

        return res;

    }
};
