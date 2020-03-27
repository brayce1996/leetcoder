// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Unique Paths.
// Memory Usage: 6.7 MB, less than 100.00% of C++ online submissions for Unique Paths.

class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        dp[0][1] = 1;
        for (int row = 1; row <= m; row++) {
            for (int col = 1; col <= n; col++) {
                dp[row][col] = dp[row - 1][col] + dp[row][col - 1];
            }
        }
        return dp[m][n];
    }
};
