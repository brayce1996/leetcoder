class Solution:
    def coinChange(self, coins: List[int], amount: int) -> int:
        dp = [-1] * (amount + 1)

        dp[0] = 0

        for coin in coins:
            if coin <= amount:
                dp[coin] = 1

        for i in range(amount+1):
            minChange = 1e15
            for coin in coins:
                if i - coin >= 0 and dp[i - coin] != -1:
                    minChange = min(minChange, dp[i-coin] + 1)

            if minChange != 1e15:
                dp[i] = minChange

        return dp[amount]
