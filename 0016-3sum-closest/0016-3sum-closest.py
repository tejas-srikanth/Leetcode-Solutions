class Solution:
    def twoSumExclude(self, nums, i, target):
        sptr = 0
        eptr = len(nums)-1
        target -= nums[i]
        bestDiff = float("inf")
        best = -1
        while sptr < eptr:
            if sptr == i:
                sptr += 1
            elif eptr == i:
                eptr -= 1
            elif nums[sptr] + nums[eptr] < target:
                if abs(target - (nums[sptr] + nums[eptr])) < bestDiff:
                    bestDiff = abs(target - (nums[sptr] + nums[eptr]))
                    best = (nums[sptr] + nums[eptr]) + nums[i]
                sptr += 1
            elif nums[sptr] + nums[eptr] > target:
                if abs(target - (nums[sptr] + nums[eptr])) < bestDiff:
                    bestDiff = abs(target - (nums[sptr] + nums[eptr]))
                    best = (nums[sptr] + nums[eptr]) + nums[i]
                eptr -= 1
            else:
                return 0, target + nums[i]
        return bestDiff, best

    def threeSumClosest(self, nums: List[int], target: int) -> int:
        nums.sort()
        smallestDiff = float("inf")
        best = -1
        if len(nums) == 3:
            return sum(nums)
        for i in range(len(nums)):
            currDiff, currBest = self.twoSumExclude(nums, i, target)
            if currDiff < smallestDiff:
                smallestDiff = currDiff
                best = currBest
        return best

        