class Solution:
    def wordBreak(self, s: str, wordDict: List[str]) -> bool:
        wordSet = set(wordDict)
        dp = [False]*(len(s) + 1)
        dp[-1] = True

        for i in range(len(s)):

            # j range from i-1 to -1
            for j in range(i-1, -2, -1):
                if dp[j] and s[j+1:i+1] in wordSet:
                    dp[i] = True
                    break

        return dp[len(s)-1]
