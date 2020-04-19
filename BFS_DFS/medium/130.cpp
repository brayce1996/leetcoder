class Solution {
public:
    int top;
    int left;
    int right;
    int bottom;
    
    void solve(vector<vector<char>>& board) {
        if (board.empty()) return;
        top = 0;
        left = 0;
        right = board[0].size() - 1;
        bottom = board.size() - 1;
        
        // top
        for (int col = 0; col <= right; col++) {
            if (board[top][col] == 'O') {
                dfsMark(board, top, col);
            }
        }
        
        // bottom
        for (int col = 0; col <= right; col++) {
            if (board[bottom][col] == 'O') {
                dfsMark(board, bottom, col);
            }
        }
        
        // left
        for (int row = 1; row < bottom; row++) {
            if (board[row][left] == 'O') {
                dfsMark(board, row, left);
            }
        }
        
        // right
        for (int row = 1; row < bottom; row++) {
            if (board[row][right] == 'O') {
                dfsMark(board, row, right);
            }
        }
        
        for (int row = 0; row <= bottom; row++) {
            for (int col = 0; col <= right; col++) {
                if (board[row][col] == 'O') board[row][col] = 'X';
                else if (board[row][col] == 'M') board[row][col] = 'O';
            }
        }
    }
    
    void dfsMark(vector<vector<char>>& board, int row, int col) {
        if (board[row][col] == 'O') {
            board[row][col] = 'M';
            if (col + 1 <= right) dfsMark(board, row, col + 1);
            if (row + 1 <= bottom) dfsMark(board, row + 1, col);
            if (col - 1 >= left) dfsMark(board, row, col - 1);
            if (row - 1 >= top) dfsMark(board, row - 1, col);
        }
    }
};
