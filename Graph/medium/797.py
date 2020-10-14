# Backtracking solution

# Complexity analysis:
# Time: O((2^n) * n)
# Space: O((2^n) * n)
class Solution:
    def allPathsSourceTarget(self, graph: List[List[int]]) -> List[List[int]]:
        n = len(graph)
        ans = []
        def dfs(currNode: int, path: List[int]):
            if currNode == n - 1:
                ans.append(path[:])
                return

            for neighbor in graph[currNode]:
                path.append(neighbor)
                dfs(neighbor, path)
                path.pop(-1)


        dfs(0, [0])

        return ans
