// Runtime: 16 ms, faster than 65.91% of C++ online submissions for Valid Sudoku.
// Memory Usage: 7.8 MB, less than 100.00% of C++ online submissions for Valid Sudoku.

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_set<char> checkSet;
        
        for (int row = 0; row < board.size(); row++) {
            for (int col = 0; col < board[0].size(); col++) {
                if (board[row][col] == '.') continue;
                if (checkSet.find(board[row][col]) != checkSet.end())
                    return false;
                checkSet.insert(board[row][col]);
            }
            checkSet.clear();
        }
        
        for (int col = 0; col < board[0].size(); col++) {
            for (int row = 0; row < board.size(); row++) {
                if (board[row][col] == '.') continue;
                if (checkSet.find(board[row][col]) != checkSet.end())
                    return false;
                checkSet.insert(board[row][col]);
            }
            checkSet.clear();
        }
        
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                for (int row = i * 3; row < (i + 1) * 3; row++) {
                    for (int col = j * 3; col < (j + 1) * 3; col++) {
                        if (board[row][col] == '.') continue;
                        if (checkSet.find(board[row][col]) != checkSet.end())
                            return false;
                        checkSet.insert(board[row][col]);
                    }
                }
                checkSet.clear();
            }
        }
        
        return true;
    }
};
