# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def lcadlHelper(self, root):
        if not root:
            return -1, root
        else:
            leftDepth, tleft = self.lcadlHelper(root.left)
            rightDepth, tright = self.lcadlHelper(root.right)
            if leftDepth == rightDepth:
                return leftDepth + 1, root
            elif leftDepth > rightDepth:
                return leftDepth + 1, tleft
            else:
                return rightDepth + 1, tright

    def lcaDeepestLeaves(self, root: Optional[TreeNode]) -> Optional[TreeNode]:
        return self.lcadlHelper(root)[1]