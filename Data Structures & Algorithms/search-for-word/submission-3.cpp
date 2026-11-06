class Solution {
public:
    void dfs(vector<vector<char>>& board, const string word, int search_depth, pair<int,int> pos, bool& found, map<pair<int,int>, int> &visited) {
        if(pos.first == board.size() || pos.first == -1) return;
        if(pos.second == board[0].size() || pos.second == -1) return;
        if(visited.find(pos) != visited.end()) return;
        if(found) return;
        if(board[pos.first][pos.second] != word[search_depth]) return;
        if(search_depth == word.size() - 1) {
            found = true;
            return;
        }

        // Getting here means that the letter matches, and need to choose to go in four directions.
        // After you explore one possibility, there is no state to restore.

        visited[pos] = 1;

        dfs(board, word, search_depth + 1, {pos.first + 1, pos.second}, found, visited);
        dfs(board, word, search_depth + 1, {pos.first - 1 , pos.second}, found, visited);
        dfs(board, word, search_depth + 1, {pos.first, pos.second + 1}, found, visited);
        dfs(board, word, search_depth + 1, {pos.first, pos.second - 1}, found, visited);

        visited.erase(pos);
        
        return;


    }
    bool exist(vector<vector<char>>& board, string word) {
        // You need to perform a backtracking dfs on each letter in the grid.
        // Stop searching if the current letter doesnt match the corresponding letter.
        // Stop searching if the current index is out of bounds of the array
        // Stop searching if the word has already been found.

        // If the search depth idx equals the length of the word, return true.

        // If the current letter matches, try going in each of the below directions:
        // (1,0) (-1,0) (0,1) (0, -1)
        bool found = false;
        pair<int,int> pos;
        for(int row = 0; row < board.size(); row++) {
            for(int col = 0; col < board[0].size(); col++) {
                pos.first = row;
                pos.second = col;

                map<pair<int,int>, int> visited;
                dfs(board, word, 0, pos, found, visited);
                if(found) return true;
            }        
        }
        return false;
        
    }
};
