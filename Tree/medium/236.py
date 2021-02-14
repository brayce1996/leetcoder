# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None
class Solution:
    def lowestCommonAncestor(self, root: 'TreeNode', p: 'TreeNode', q: 'TreeNode') -> 'TreeNode':
        def buildPath(curr: 'TreeNode', path): # time: number of recurssion call O(n), space: stack size would be O(n), which n is the number of nodes in the tree
          	nonlocal pPath, qPath

          	if curr == None:
                return

          	if curr.val == p:
              	pPath = path[:] # O(n)

          	if curr.val == q:
              	qPath = path[:] # O(n)

            # backtracking
            path.append(curr.left)
            buildPath(curr.left, path)
            path.pop()
            path.append(curr.right)
            buildPath(curr.right, path)
            path.pop()

        # build path
        pPath = []
        qPath = []
        buildPath(root, [root])

        # compare path and find the LCA
        lca = None
        for i in range(min(len(pPath), len(qPath))): # O(n)
          	if pPath[i].val != qPath[i].val:
              	lca = pPath[i-1]
                break

        # when p is the ancestor for q, or vise versa
        if lca == None:
            lca = pPath[min(len(pPath), len(qPath)) - 1]

        return lca
