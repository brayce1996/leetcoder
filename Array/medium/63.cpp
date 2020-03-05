// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Unique Paths II.
// Memory Usage: 8.8 MB, less than 100.00% of C++ online submissions for Unique Paths II.

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        if(obstacleGrid.empty() || obstacleGrid[0].empty())
            return 0;
        int rowSize = obstacleGrid.size();
        int colSize = obstacleGrid[0].size();
        
        vector<vector<long long>> dp(rowSize + 1, vector<long long>(colSize + 1, 0));
        dp[0][1] = 1;
        
        for (int row = 1; row <= rowSize; row++) {
            for (int col = 1; col <= colSize; col++) {
                if (obstacleGrid[row - 1][col - 1] == 0)
                    dp[row][col] = dp[row - 1][col] + dp[row][col - 1];
            }
        }
        
        return dp[rowSize][colSize];
    }
};
