class Solution:
    def searchRange(self, nums: List[int], target: int) -> List[int]:
        lo = 0
        hi = len(nums)-1
        if len(nums) == 0:
            return [-1, -1]
        while lo < hi:
            mid = (lo + hi) // 2
            if nums[mid] < target:
                lo = mid + 1
            else:
                hi = mid
        left = lo if nums[lo] == target else -1
        lo = 0
        hi = len(nums)-1
        while lo < hi:
            mid = (lo + hi + 1) // 2
            if nums[mid] > target:
                hi = mid - 1
            else:
                lo = mid
        return [left, hi if nums[hi] == target else -1]