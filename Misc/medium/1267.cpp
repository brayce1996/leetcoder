class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<int> rowSum(m, 0);
        int disconnectCount = 0;
        int serverCount = 0;

        for (int row = 0; row < m; row++) {
            for (int col = 0; col < n; col++) {
                rowSum[row] += grid[row][col];
            }
            serverCount += rowSum[row];
        }

        for (int col = 0; col < n; col++) {
            int colSum = 0;
            for (int row = 0; row < m; row++) {
                colSum += grid[row][col];
            }
            if (colSum == 1) {
                for (int row = 0; row < m; row++) {
                    if (rowSum[row] == 1 && grid[row][col] == 1) {
                        disconnectCount++;
                    }
                }
            }
        }
        return serverCount - disconnectCount;
    }
};
