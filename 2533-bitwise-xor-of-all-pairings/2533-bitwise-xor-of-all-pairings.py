class Solution:
    def xorAllNums(self, nums1: List[int], nums2: List[int]) -> int:
        n2xor = 0
        if len(nums1) % 2 == 1:
            for i in range(len(nums2)):
                n2xor ^= nums2[i]
        n1xor = 0
        if len(nums2) % 2 == 1:
            for i in range(len(nums1)):
                n1xor ^= nums1[i]
        return n2xor ^ n1xor
        