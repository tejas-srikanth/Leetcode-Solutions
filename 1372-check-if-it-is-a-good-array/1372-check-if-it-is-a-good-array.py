import math
class Solution:
    def isGoodArray(self, nums: List[int]) -> bool:
        currNum = nums[0]
        for i in range(1, len(nums)):
            currNum = math.gcd(nums[i], currNum)
        return currNum == 1