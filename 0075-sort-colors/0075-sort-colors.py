class Solution:
    def partitionArray(self, nums, start, begNum):
        sPtr = start
        ePtr = len(nums)-1
        while sPtr < ePtr:
            while sPtr < ePtr and nums[sPtr] == begNum:
                sPtr += 1
            while sPtr < ePtr and nums[ePtr] != begNum:
                ePtr -= 1
            if (sPtr >= ePtr):
                break
            nums[sPtr], nums[ePtr] = nums[ePtr], nums[sPtr]
        return sPtr

    def sortColors(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        newStart = self.partitionArray(nums, 0, 0)
        newparition = self.partitionArray(nums, newStart, 1)
        

        