# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def buildTree(self, preorder: List[int], inorder: List[int]) -> Optional[TreeNode]:
        if preorder == [] and inorder == []:
            return None
        elif len(preorder) == 1 and len(inorder) == 1:
            return TreeNode(val=preorder[0])
        else:
            inorder_partition = 0
            for i in range(len(inorder)):
                if len(preorder) == 0:
                    print("HI")
                if inorder[i] == preorder[0]:
                    inorder_partition = i
                    break
            if inorder_partition == 0:
                t = TreeNode(val=preorder[0])
                t.right = self.buildTree(preorder[1:], inorder[1:])
                return t
            if inorder_partition == len(inorder) - 1:
                t = TreeNode(val=preorder[0])
                t.left = self.buildTree(preorder[1:], inorder[:inorder_partition])
                return t
            for j in range(len(preorder)):
                if preorder[j] == inorder[inorder_partition-1]:
                    t = TreeNode(val=preorder[0])
                    t.left = self.buildTree(preorder[1:inorder_partition+1], inorder[:inorder_partition])
                    t.right = self.buildTree(preorder[inorder_partition+1:], inorder[inorder_partition+1:])
                    return t
            return TreeNode(val=15000)

        