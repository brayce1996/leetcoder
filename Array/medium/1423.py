class Solution:
    def maxScore(self, cardPoints: List[int], k: int) -> int:
        runSum = 0
        prefixSum = []
        for point in cardPoints:
            runSum += point
            prefixSum.append(runSum)
        prefixSum.append(0) # for prefixSum[-1]

        notSelectNum = len(cardPoints) - k
        if notSelectNum == 0:
            return runSum
        maxPoint = 0

        for notSelectStart in range(k+1):
            maxPoint = max(maxPoint, runSum - (prefixSum[notSelectStart + notSelectNum - 1] - prefixSum[notSelectStart - 1]))

        return maxPoint
