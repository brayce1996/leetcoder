// Runtime: 72 ms, faster than 58.53% of C++ online submissions for Search a 2D Matrix II.
// Memory Usage: 12.1 MB, less than 100.00% of C++ online submissions for Search a 2D Matrix II.

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
    	if (matrix.empty() || matrix[0].empty())
    		return false;
    	int rowSize = matrix.size();
        int colSize = matrix[0].size();
        
        int row = 0;
        int col = colSize - 1;
        while (row < rowSize && col >= 0) {
            if (matrix[row][col] == target)
                return true;
            else if (matrix[row][col] > target)
                col--;
            else row++;
        }
        
        return false;
    }
};
