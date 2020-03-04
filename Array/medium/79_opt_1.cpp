// Runtime: 112 ms, faster than 45.55% of C++ online submissions for Word Search.
// Memory Usage: 35.8 MB, less than 50.00% of C++ online submissions for Word Search.

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        if (board.size() < 1 || board[0].size() < 1 || word.length() < 1)
            return false;
        
        for (int row = 0; row < board.size(); row++) {
            for (int col = 0; col < board[row].size(); col++) {
                // try a new start at board[row][col]
                if (dfs(board, word, 0, row, col))
                    return true;
            }
        }
        return false;
    }

private:
    int drow[4] = {1,-1,0,0};
    int dcol[4] = {0,0,1,-1};
    bool dfs(vector<vector<char>>& board, string word, int wordIndex, int row, int col) {
        // return if current position is not part of the answer or is visited by predecessor
        if (board[row][col] != word[wordIndex])
            return false;
        
        // ====current position is part of the answer!====
        
        if (wordIndex == word.length() - 1)
            return true;

        // set current position to 'visited', so the descendants will NOT visit current position again
        board[row][col] = '*';

        // reach out to find answer and collect the result
        bool result = false;
        for (int i = 0; i < 4; i++) {
            int newRow = row + drow[i];
            int newCol = col + dcol[i];
            if (newRow < board.size() && newRow >= 0 && newCol < board[row].size() && newCol >= 0) {
                if (dfs(board, word, wordIndex + 1, newRow, newCol)) {
                    result = true;
                    break;
                }
                
            }
        }

        // set current position to non-visited, so the predecessors CAN visit current position again
        board[row][col] = word[wordIndex]; // reset to original char of current position
        
        return result;
    }
};
