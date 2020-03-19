// Runtime: 464 ms, faster than 9.27% of C++ online submissions for Search a 2D Matrix II.
// Memory Usage: 12.1 MB, less than 100.00% of C++ online submissions for Search a 2D Matrix II.

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
    	if (matrix.empty() || matrix[0].empty())
    		return false;
    	return search(matrix, target, 0, matrix.size() - 1, 0, matrix[0].size() - 1); 
    }

    bool search(vector<vector<int>>& matrix, int target, int top, int bottom, int left, int right) {
    	// boundary check
    	if (top < 0 || top > bottom || bottom >= matrix.size() || left < 0 || left > right || right >= matrix[0].size())
    		return false;

    	//cout << matrix[(top + bottom) / 2][(left + right) / 2] << endl;

    	if (bottom == top && right == left) {
    		return (matrix[top][left] == target);
    	}

    	int row = (top + bottom) / 2;
    	int col = (left + right) / 2;
    	bool result = false;
    	if (matrix[row][col] == target)
    		return true;
    	else if (matrix[row][col] > target) {
    		// search top left
    		result |= search(matrix, target, top, row - 1, left, col - 1);

			// search top right
			if (!result) result |= search(matrix, target, top, row - 1, col, right);

			// search bottom left
			if (!result) result |= search(matrix, target, row, bottom, left, col - 1);
    	} else {
    		// search bottom right
    		result |= search(matrix, target, row + 1, bottom, col + 1, right);

			// search top right
			if (!result) result |= search(matrix, target, top, row, col + 1, right);

			// search bottom left
			if (!result) result |= search(matrix, target, row + 1, bottom, left, col);
    	}
    	return result;

    }
};