# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def findBottomLeftValue(self, root: TreeNode) -> int:
        self.currBottomLevel = 0
        self.currBottomNum = root.val
        self.dfs(root, 0)
        return self.currBottomNum

    def dfs(self, root: TreeNode, level: int):
        if root.left == None and level > self.currBottomLevel:
            self.currBottomNum = root.val
            self.currBottomLevel = level

        if root.left != None:
            self.dfs(root.left, level+1)

        if root.right != None:
            self.dfs(root.right, level+1)

