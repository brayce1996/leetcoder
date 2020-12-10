class Solution:
    def findTargetSumWays(self, nums: List[int], S: int) -> int:
        sumWays = dict()
        sumWays[0] = 1

        for num in nums:
            nextSumWays = dict()
            for aSum in sumWays:
                if aSum+num not in nextSumWays:
                    nextSumWays[aSum+num] = 0
                if aSum-num not in nextSumWays:
                    nextSumWays[aSum-num] = 0

                nextSumWays[aSum+num] += sumWays[aSum]
                nextSumWays[aSum-num] += sumWays[aSum]
            sumWays = nextSumWays

        # for (key, val) in sumWays.items():
        #     print("{} {}".format(key, val))

        return sumWays[S] if S in sumWays else 0
