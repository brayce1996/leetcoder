class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        if (grid.empty()) return -1;
        int n = grid.size();

        queue<pair<int, int>> bfsQueue;

        for (int row = 0; row < n; row++) {
            for (int col = 0; col < n; col++) {
                if (grid[row][col] == 1) {
                    bfsQueue.push(pair<int, int>(row, col));
                }
            }
        }

        int directions[4][4] = {
            {-1,0}, {1,0}, {0,-1}, {0,1}
        };

        int maxNearLand = -1;

        while (!bfsQueue.empty()) {
            pair<int, int> curr = bfsQueue.front();
            bfsQueue.pop();
            int row = curr.first;
            int col = curr.second;

            for (auto dir: directions) {
                int nextRow = row + dir[0];
                int nextCol = col + dir[1];
                if (nextRow >= 0 && nextRow < n && nextCol >= 0 && nextCol < n &&
                    grid[nextRow][nextCol] == 0) {
                    bfsQueue.push(pair<int, int>(nextRow, nextCol));
                    grid[nextRow][nextCol] = grid[row][col] + 1;
                    maxNearLand = max(maxNearLand, grid[nextRow][nextCol]);
                }
            }
        }

        return max(-1, maxNearLand - 1);
    }
};
