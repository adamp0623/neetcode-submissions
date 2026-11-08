class Solution {
public:
    vector<vector<bool>> update_state(int n, int q_r, int q_c, vector<vector<bool>> game_state) {

        vector<pair<int,int>> dirs = {{1,1}, {-1, 1}, {1, -1}, {-1,-1}, {1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        for(auto dir:dirs) {
            int r = q_r;
            int c = q_c;
            while(r < n && c < n && r >= 0 && c >= 0) {
                game_state[r][c] = true;
                r += dir.first;
                c += dir.second;
            }
        }

        return game_state;

        
    }


    // void backtrack(const int& n, int num_queens, int r, int c, vector<vector<bool>> game_state, vector<string> board, vector<vector<string>>& res) {
    //     if (c == n) {
    //         r++;
    //         c = 0;
    //     }

    //     if (r == n) {
    //         if (num_queens == n) res.push_back(board);
    //         return;
    //     }
        
    //     // First check if you can place a queen:
    //     if(!game_state[r][c]) {
    //         // You can place a queen.
    //         board[r][c] = 'Q';
    //         backtrack(n, num_queens + 1, r, c + 1, update_state(n, r, c, game_state), board, res);
    //         board[r][c] = '.';

    //     }
    //     // Dont place a queen.a
    //     backtrack(n, num_queens, r, c+1, game_state, board, res);
    //     return;
    // }
    void backtrack(int n, int r,
               vector<vector<bool>> game_state,
               vector<string> board,
               vector<vector<string>>& res) {
    if (r == n) {
        res.push_back(board);
        return;
    }

    for (int c = 0; c < n; c++) {
        if (game_state[r][c]) continue;

        // Choose this column for the queen in row r.
        board[r][c] = 'Q';

        backtrack(n, r + 1,
                  update_state(n, r, c, game_state),
                  board, res);

        // Undo before trying another column in this row.
        board[r][c] = '.';
    }
               }

    vector<vector<string>> solveNQueens(int n) {
        // At each square, you can place a queen there, or you dont place a queen.
        // If you cant place a queen, 
        // Recurse to the next tile, finding the solution if you didnot place a queen there.
        // Then undo that selection.
        // If you can, place a queen, move to the next tile.
        // Recurse to the next tile, finding the solutoins if you did palce a queen there.
        // Then undo that choice, to find other possibilityies.

        // Placing a queen at position (i, j) then blocks other queens from being placed:
        // At the row i, at the row j, and at (i+1,j+1)/(i-1, j-1) -> to end of the board.
        // You should keep a copy of the map of where you can play or cant play.
        // Generate an nxn map of zeros. When a queen is placed, update the map
        // with the correct tiles flipped to 1, indicating that a queen cannot be played 
        // there.

        // Also have a map of where queens have been played. Initialize as [....], [....]

        // If the idx (where you choose to play/not play a queen) is out of bounds,
        // and all queens have been played, add that board state to the result.

        vector<string> board;
        vector<vector<bool>> game_state;
        for(int i = 0; i < n; i++) {
            string row;
            vector<bool> state_row;
            for(int j = 0; j < n; j++) {
                row.push_back('.');
                state_row.push_back(false);
            }
            board.push_back(row);
            game_state.push_back(state_row);
        }
        // This creates a board and game state matrices.
        vector<vector<string>> res;
        backtrack(n, 0, game_state, board, res);
        return res;


    }
};
