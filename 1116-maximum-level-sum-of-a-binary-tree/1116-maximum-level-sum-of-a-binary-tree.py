from collections import deque
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def maxLevelSum(self, root: Optional[TreeNode]) -> int:
        pq = deque()
        pq.append(root)
        maxSum = root.val
        maxLevel = 1
        currLevel = 1
        while pq:
            s = 0
            lpq = len(pq)
            for _ in range(lpq):
                out = pq.popleft()
                s += out.val
                if out.right is not None:
                    pq.append(out.right)
                if out.left is not None:
                    pq.append(out.left)
            if s > maxSum:
                maxSum = s
                maxLevel = currLevel
            currLevel += 1
        return maxLevel