class Solution:
    def countBits(self, num: int) -> List[int]:
        if num == 0:
            return [0]

        dp = [0, 1]
        base = 1
        for i in range(2, num+1):
            if i == base * 2:
                dp.append(1)
                base = i
            else:
                dp.append(1 + dp[i - base])
        return dp
