class Solution:
    def maxOperations(self, nums: List[int], k: int) -> int:
        nums.sort()
        print(nums)
        st = 0
        end = len(nums) - 1
        numP = 0
        while st < end:
            if nums[st] + nums[end] < k:
                st = st + 1
            elif nums[st] + nums[end] > k:
                end = end - 1
            else:
                numP += 1
                st += 1
                end -= 1
        return numP
        