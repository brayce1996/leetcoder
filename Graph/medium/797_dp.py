# DP solution

# Complexity analysis:
# Time: O((2^n) * n)
# Space: O((2^n) * n)
class Solution:
    def allPathsSourceTarget(self, graph: List[List[int]]) -> List[List[int]]:
        n = len(graph)
        ans = []
        mem = [None] * n
        def dfs(currNode: int):
            if mem[currNode]:
                return

            # init
            mem[currNode] = []

            for neighbor in graph[currNode]:
                dfs(neighbor)
                for path in mem[neighbor]:
                    mem[currNode].append([currNode] + path)


        mem[n - 1] = [[n - 1]]
        dfs(0)

        return mem[0]
