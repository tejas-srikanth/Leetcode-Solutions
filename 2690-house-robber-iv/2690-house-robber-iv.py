class Solution:
    def isValid(self, nums, guess, k):
        numThefts = 0
        i = 0
        while i < len(nums):
            if nums[i] <= guess:
                numThefts += 1
                i += 1
            i += 1
        return numThefts >= k


    def minCapability(self, nums: List[int], k: int) -> int:
        lo = 1
        hi = max(nums)
        while lo < hi:
            mid = (lo + hi - 1) // 2
            if (self.isValid(nums, mid, k)):
                hi = mid
            else:
                lo = mid + 1
        return lo