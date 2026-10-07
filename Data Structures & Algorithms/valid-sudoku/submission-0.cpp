class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        // Need to iterate across rows, columns, and sub squares
        // Add values to a set for each small box, if it already exists in the set, 
        // return false;.
        
        // This iterates across rows.
        for(const auto row:board) {
            unordered_set<char> seen;
            for(const char col:row) {
                if(col == '.') continue;
                if(seen.find(col) != seen.end()) return false;
                seen.insert(col);
            }
        }

        // Checks all the columns.
        for(int i = 0; i < board.size(); i++) {
            unordered_set<char> seen;
            for(int j = 0; j < board.size(); j++) {
                if(board[j][i] == '.') continue;
                if(seen.find(board[j][i]) != seen.end()) return false;
                seen.insert(board[j][i]);
            }
        }

        // Need to check the three by three squares.
        // Break up the grid into a larger 3 by 3 grid.
        for(int i = 0; i < 3; i++) {
            for(int j = 0; j < 3; j++) {
                // We have i,j indexes for subsquare 0, 1, 2
                // For box 1,1 indexes for subquare are 3,4,5:3,4,5
                // Can take i,j index, board[3*i + k][3*j + l]
                unordered_set<char> seen;
                for(int k = 0; k < 3; k++) {
                    for(int l = 0; l < 3; l++) {
                        if(board[3*i+k][3*j+l] == '.') continue;
                        if(seen.find(board[3*i+k][3*j+l]) != seen.end()) return false;
                        seen.insert(board[3*i+k][3*j+l]);
                    }
                }
            }
        }

        return true;

    }
};
