# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def zzHelper(self, root, currAmt, currDir):
        if not root:
            return max(currAmt - 1, 0)
        else:
            maxPath = currAmt
            if root.left:
                maxPath = max(maxPath, self.zzHelper(root.left, 0 if currDir == 0 else currAmt + 1, 0))
            if root.right:
                maxPath = max(maxPath, self.zzHelper(root.right, 0 if currDir == 1 else currAmt + 1, 1))
            return maxPath

    def longestZigZag(self, root: Optional[TreeNode]) -> int:
        return self.zzHelper(root, -1, 0) + 1