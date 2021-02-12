# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def isValidBST(self, root: TreeNode) -> bool:
        def helper(curr: TreeNode, lowerBound: int, upperBound: int):
            if curr == None:
                return True

            if (lowerBound != None and lowerBound >= curr.val) or (upperBound != None and curr.val >= upperBound):
                return False

            return helper(curr.left, lowerBound, curr.val) and helper(curr.right, curr.val, upperBound)

        return helper(root, None, None)


