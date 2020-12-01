class Solution:
    def countSquares(self, matrix: List[List[int]]) -> int:
        count = 0

        for i in range(len(matrix)):
            count += matrix[i][0]

        for i in range(1, len(matrix[0])):
            count += matrix[0][i]

        for row in range(1, len(matrix)):
            for col in range(1, len(matrix[0])):
                if matrix[row][col] == 1:
                    minSide = min(matrix[row-1][col-1],
                        matrix[row-1][col],
                        matrix[row][col-1])

                    matrix[row][col] = minSide + 1
                    count += matrix[row][col]

        return count
