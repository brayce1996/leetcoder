class Solution {
public:
    int rowSize;
    int colSize;
    
    int numIslands(vector<vector<char>>& grid) {
        if (grid.empty()) return 0;
        rowSize = grid.size();
        colSize = grid[0].size();
        int islandCount = 0;
        
        for (int row = 0; row < rowSize; row++) {
            for (int col = 0; col < colSize; col++) {
                if (grid[row][col] == '1') {
                    expand(grid, row, col);
                    islandCount++;
                }
            }
        }
        return islandCount;
    }
    
    void expand(vector<vector<char>>& grid, int row, int col) {
        if (grid[row][col] == '1') {
            grid[row][col] = 'M';
            if (col + 1 < colSize) expand(grid, row, col + 1);
            if (row + 1 < rowSize) expand(grid, row + 1, col);
            if (col > 0) expand(grid, row, col - 1);
            if (row > 0) expand(grid, row - 1, col);
        }
    }
};
