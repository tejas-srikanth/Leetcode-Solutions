class Solution:
    def subsetXORSum(self, nums: List[int]) -> int:
        allSums = [0]
        for i in range(len(nums)):
            sumLen = len(allSums)
            for j in range(sumLen):
                allSums.append(allSums[j] ^ nums[i])
        return sum(allSums)