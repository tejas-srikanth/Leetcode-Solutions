class Solution:
    def maximumTripletValue(self, nums: List[int]) -> int:
        maxFromRight = [nums[-1]]
        currMax = nums[-1]
        for i in range(len(nums)-2, -1, -1):
            currMax = max(currMax, nums[i])
            maxFromRight.append(currMax)
        maxFromRight.reverse()
        st = nums[0]
        currMax = 0
        for i in range(1, len(nums)-1):
            currMax = max(currMax, (st - nums[i]) * maxFromRight[i + 1])
            st = max(st, nums[i])
        return currMax