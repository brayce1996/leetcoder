class Solution:
    def longestPalindromeSubseq(self, s: str) -> int:
        curr = [0] * len(s)
        nextLine = [1] * len(s)
        nextNextLine = [0] * len(s)

        for col in range(1, len(s)):
            for i in range(len(s) - col):
                j = col + i
                if (s[i] == s[j]):
                    curr[j] = nextNextLine[j-1] + 2
                else:
                    curr[j] = max(nextLine[j], nextLine[j-1])
            nextNextLine = nextLine[:]
            nextLine = curr[:]


        return nextLine[len(s)-1]

