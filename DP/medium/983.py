class Solution:
    def mincostTickets(self, days: List[int], costs: List[int]) -> int:
        def findDayIndex(day: int) -> int:
            low, high = 0, len(days)-1

            while low < high:
                mid = (low + high) // 2

                if days[mid] < day:
                    low = mid + 1
                else:
                    high = mid
            return low if days[low] >= day else -1

        dp = [365000]*(len(days)+1)
        dp[-1] = 0

        ticketDay = [1, 7, 30]

        for i in range(len(days)-1, -1, -1):
            for j in range(len(costs)):
                ticketExpireDay = findDayIndex(days[i] + ticketDay[j])
                dp[i] = min(dp[i], dp[ticketExpireDay] + costs[j])

        return dp[0]
