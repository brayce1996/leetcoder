class Solution:
    def minCost(self, costs: List[List[int]]) -> int:
        if (len(costs)==0):
            return 0

        for houseIndex in range(1, len(costs)):
            for color in range(3):
                costs[houseIndex][color] = min(costs[houseIndex-1][(color+1)%3],
                    costs[houseIndex-1][(color+2)%3]) + costs[houseIndex][color]

        return min(costs[-1])
