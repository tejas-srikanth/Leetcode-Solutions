class Solution:
    def getMaximumXor(self, nums: List[int], maximumBit: int) -> List[int]:
        arr = []
        rollingXOR = 0
        mask = 2 ** (maximumBit) - 1
        for num in nums:
            rollingXOR ^= num
            arr.append((rollingXOR | mask) ^ rollingXOR)
        arr.reverse()
        return arr