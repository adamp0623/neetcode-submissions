class Solution {
public:
    void solve(vector<vector<char>>& board) {
        // We need to capture surronded regions. 
        // Instead of capturing regions by running traversal on inner
        // 'O's  and flipping their values, instead run traversals
        // on the outer O's to indicate which values should not be 
        // flipped. Then flip all values except those that exist in the 
        // visited sets.

        // First need to get all the starting locations.
        // Only need the perimeter of the board, which is 2m + 2n time, which is O(m+n)
        queue<pair<int,int>> q;
        for(int i = 0; i < board.size(); i++) {
            // Add first and last location of each row, if its a 'O'
            if(board[i][0] == 'O') {
                q.push({i, 0});
                board[i][0] = '#';
            }
            if(board[i][board[0].size() - 1] == 'O') {
                q.push({i, board[0].size() - 1});
                board[i][board[0].size() - 1] = '#';
            }

        }
        for(int j = 0; j < board[0].size(); j++) {
            // So corners are not double counted
            if(j == 0 || j == board[0].size() - 1) continue;
            if(board[0][j] == 'O') {
                q.push({0, j}); 
                board[0][j] = '#';
                cout << j << endl;
            }
            if(board[board.size()-1][j] == 'O') {
                q.push({board.size() - 1, j});
                board[board.size()-1][j] = '#';
            }
        }

        // To mark visited, change the value to a different character, like '#'
        while(!q.empty()) {

            auto pos = q.front();
            cout << pos.first << endl;
            cout << pos.second << endl;
            q.pop();

            vector<pair<int,int>> dirs = {{1,0}, {-1,0}, {0,1}, {0,-1}};
            for(auto dir:dirs) {
                int r = pos.first + dir.first;
                int c = pos.second + dir.second;
                if(r < 0 || c < 0 || r >= board.size() || c >= board[0].size()) continue;
                if(board[r][c] == '#' || board[r][c] == 'X') continue;

                // This means that the current node is neighbor, and is a 'O'
                // It should be added to the solution set, and marked visited.
                board[r][c] = '#';
                q.push({r,c});
            }
        }

        for(int i = 0; i < board.size(); i++) {
            for(int j = 0; j < board[0].size(); j++) {
                if(board[i][j] == '#') board[i][j] = 'O';
                // If it hasnt been marked visited, it should be a X.
                else board[i][j] = 'X';
            }
        }

        return;


    }
};
