class Solution:
    def minimumIndex(self, nums: List[int]) -> int:
        d = {}
        elt = nums[0]
        for i in nums:
            if i not in d:
                d[i] = 0
            d[i] += 1
            if d[i] > len(nums) // 2:
                elt = i
        numOccur = d[elt]
        currOccur = 0
        for i in range(len(nums)):
            if nums[i] == elt:
                currOccur += 1
            if (currOccur > (i + 1) // 2 and numOccur - currOccur > (len(nums) - i - 1) // 2):
                return i
        return -1