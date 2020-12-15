class Solution:
    def longestPalindromeSubseq(self, s: str) -> int:
        self.mem = dict()
        return self.helper(s, 0, len(s)-1)

    def helper(self, s, i, j) -> int:
        if i > j:
            return 0
        if i == j:
            return 1
        if (i, j) in self.mem:
            return self.mem[(i, j)]
        if s[i] == s[j]:
            self.mem[(i, j)] = self.helper(s, i+1, j-1) + 2
        else:
            self.mem[(i, j)] = max(self.helper(s, i+1, j), self.helper(s, i, j-1))
        return self.mem[(i, j)]

