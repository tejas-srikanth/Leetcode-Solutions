# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def deleteNode(self, root: Optional[TreeNode], key: int) -> Optional[TreeNode]:
        if root is None:
            return root
        elif root.val == key:
            if not root.right:
                return root.left
            else:
                curr = root.right
                prev = root.right
                parent = root
                if root.right.left is None:
                    root.right.left = root.left
                    return root.right

                while curr is not None:
                    parent = prev
                    prev = curr
                    curr = curr.left
                root.val = prev.val
                parent.left = prev.right
                return root
        else:
            if key > root.val:
                root.right = self.deleteNode(root.right, key)
            else:
                root.left = self.deleteNode(root.left, key)
            return root