class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int rowSize = grid.size();
        int colSize = grid[0].size();
        queue<pair<int, int>*> bfsQueue;
        
        // search rotten orange
        for (int row = 0; row < rowSize; row++) {
            for (int col = 0; col < colSize; col++) {
                if (grid[row][col] == 2) {
                    pair<int, int>* rottenPosition = new pair<int, int>(row, col);
                    bfsQueue.push_back(rottenPosition);
                }
            }
        }

        // start bfs
        int iteration = 0;
        int drow[4] = {1,-1,0,0};
        int dcol[4] = {0,0,1,-1};
        while (!bfsQueue.empty()) {
            pair<int, int>* rottenPosition = bfsQueue.front();
            bfsQueue.pop();
            
            for (int i = 0; i < 4; i++) {
                
            }
        }

        return iteration;
    }
};
