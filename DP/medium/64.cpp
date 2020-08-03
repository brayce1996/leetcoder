class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        if (grid.empty() || grid[0].empty())
            return 0;
        
        int rowSize = grid.size();
        int colSize = grid[0].size();
        vector<int> dp(colSize);
        
        // init dp
        dp[0] = grid[0][0];
        for (int col = 1; col < colSize; col += 1) {
            // nodes in the first row can only be visited from the left node of them
            dp[col] = dp[col - 1] + grid[0][col];
        }
        
        for (int row = 1; row < rowSize; row += 1) {
            // first node of each row can only be visited from first node of last row
            dp[0] = dp[0] + grid[row][0];
            for (int col = 1; col < colSize; col += 1) {
                // record the min way to visit current node (from up or left)
                dp[col] = min(dp[col], dp[col - 1]) + grid[row][col];
            }
        }
        
        return dp[colSize - 1];
    }
};
