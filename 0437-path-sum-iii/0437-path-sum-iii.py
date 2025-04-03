# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def pathSumHelper(self, root, targetSum, allSums):
        currSum = root.val + allSums[-1]
        numSums = 0
        if currSum - targetSum in allSums:
            numSums += allSums.count(currSum - targetSum)
        allSums.append(currSum)
        if root.left:
            numSums += self.pathSumHelper(root.left, targetSum, allSums)
        if root.right:
            numSums += self.pathSumHelper(root.right, targetSum, allSums)
        allSums.pop()
        return numSums

    def pathSum(self, root: Optional[TreeNode], targetSum: int) -> int:
        if not root:
            return 0
        allSums = [0]
        return self.pathSumHelper(root, targetSum, allSums)