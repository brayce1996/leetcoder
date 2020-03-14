// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Rotate Image.
// Memory Usage: 8.4 MB, less than 100.00% of C++ online submissions for Rotate Image.

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        if(matrix.empty() || matrix[0].empty())
            return;
        
        int rowSize = matrix.size();
        int colSize = matrix[0].size();
        
        int rowLimit = rowSize / 2 + rowSize % 2;
        for (int row = 0; row < rowLimit; row++) {
            for (int col = row; col < colSize - row - 1; col++) {
                // calculate indices
                pair<int, int> rightTop(col, colSize - row - 1);
                pair<int, int> rightBottom(rowSize - row - 1, colSize - col - 1);
                pair<int, int> leftBottom(colSize - col - 1, row);

                // save values
                int righTopVal = matrix[rightTop.first][rightTop.second];
                int rightBottomVal = matrix[rightBottom.first][rightBottom.second];
                int leftBottomVal = matrix[leftBottom.first][leftBottom.second];

                // assign(transfer) values
                matrix[rightTop.first][rightTop.second] = matrix[row][col];
                matrix[rightBottom.first][rightBottom.second] = righTopVal;
                matrix[leftBottom.first][leftBottom.second] = rightBottomVal;
                matrix[row][col] = leftBottomVal;
            }
        }
    }
};
