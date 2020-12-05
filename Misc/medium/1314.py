class Solution:
    def matrixBlockSum(self, mat: List[List[int]], K: int) -> List[List[int]]:
        rowLen, colLen = len(mat), len(mat[0])
        rangeSum = [[0]*(colLen+1) for row in range(rowLen+1)]
        rangeSum[0][0] = mat[0][0]

        for row in range(1, rowLen):
            rangeSum[row][0] = mat[row][0] + rangeSum[row-1][0]
        for col in range(1, colLen):
            rangeSum[0][col] = mat[0][col] + rangeSum[0][col-1]

        for row in range(1, rowLen):
            for col in range(1, colLen):
                rangeSum[row][col] = rangeSum[row-1][col] + rangeSum[row][col-1] - rangeSum[row-1][col-1] + mat[row][col]

        for row in range(rowLen):
            for col in range(colLen):
                outLeft = max(col - K - 1, -1)
                right = min(col + K, colLen - 1)
                outuUp = max(row - K - 1, -1)
                bottom = min(row + K, rowLen - 1)

                mat[row][col] = rangeSum[bottom][right] - rangeSum[bottom][outLeft] - rangeSum[outuUp][right] + rangeSum[outuUp][outLeft]


        return mat
