class Node:
    def __init__(self, variable: str):
        self.variable = variable
        self.adj = []
        self.addAdj(variable, 1) # link self

    def addAdj(self, variable: str, value: float):
        self.adj.append((variable, value))

class Solution:
    def calcEquation(self, equations: List[List[str]], values: List[float], queries: List[List[str]]) -> List[float]:

        nodes = dict()
        def dfs(curr: str, target: str, value: float) -> (bool, float):
            if curr not in nodes:
                return False, -1
            for neighbor in nodes[curr].adj:
                var, val = neighbor
                if var not in visited:
                    if var == target:
                        return True, value * val
                    else:
                        visited.add(var)
                        valid, result = dfs(var, target, value * val)
                        visited.remove(var)
                        if valid:
                            return True, result
            return False, -1

        # build graph
        for i, eq in enumerate(equations):
            a, b = eq
            if a not in nodes:
                nodes[a] = Node(a)
            if b not in nodes:
                nodes[b] = Node(b)
            nodes[a].addAdj(b, values[i])
            nodes[b].addAdj(a, 1 / values[i])

        # execute queries
        answers = []
        for c, d in queries:
            visited = set()
            valid, result = dfs(c, d, 1)
            answers.append(result)
        return answers
