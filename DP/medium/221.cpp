class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if (matrix.empty()) return 0;
        int rowSize = matrix.size();
        int colSize = matrix[0].size();
        int ans = 0;
        for (int row = 0; row < rowSize; row++) {
            for (int col = 0; col < colSize; col++) {
                if (matrix[row][col] == '1') {
                    if (row > 0 && col > 0) {
                        char min = min3(matrix[row-1][col-1],
                                       matrix[row][col-1],
                                       matrix[row-1][col]);
                        matrix[row][col] = min + 1;
                    }
                    ans = max(ans, matrix[row][col] - '0');
                }
            }
        }
        return ans*ans;
    }

    char min3(char a, char b, char c) {
        return min(min(a, b), c);
    }
};
