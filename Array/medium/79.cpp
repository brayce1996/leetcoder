class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        if (board.size() < 1 || board[0].size() < 1 || word.length() < 1)
            return false;

        vector<vector<bool>> isVisited(board.size(), vector<bool>(board[0].size(), false));
        for (int row = 0; row < board.size(); row++) {
            for (int col = 0; col < board[row].size(); col++) {
                // try a new start at board[row][col]
                if (dfs(board, isVisited, word, 0, row, col))
                    return true;
            }
        }
        return false;
    }

private:
    bool dfs(vector<vector<char>>& board, vector<vector<bool>>& isVisited, string word, int wordIndex, int row, int col) {
        // excceed the end of the target word
        if (wordIndex >= word.length())
            return false;
        
        // rule out invalid coordinate
        if (row >= board.size() || row < 0
                || col >= board[row].size() || col < 0)
            return false;
        
        // return if current position is not part of the answer or is visited by predecessor
        if (board[row][col] != word[wordIndex] || isVisited[row][col])
            return false;
        
        // ====current position is part of the answer!====
        
        // reach the end of the word
        if (wordIndex == word.length() - 1)
            return true;

        // set current position to visited, so the descendants will NOT visit current position again
        isVisited[row][col] = true;

        // reach out to find answer and collect the result
        bool result = dfs(board, isVisited, word, wordIndex + 1, row + 1, col)
            || dfs(board, isVisited, word, wordIndex + 1, row - 1, col)
            || dfs(board, isVisited, word, wordIndex + 1, row, col + 1)
            || dfs(board, isVisited, word, wordIndex + 1, row, col - 1);

        // set current position to non-visited, so the predecessors CAN visit current position again
        isVisited[row][col] = false;
        
        return result;
    }
};
