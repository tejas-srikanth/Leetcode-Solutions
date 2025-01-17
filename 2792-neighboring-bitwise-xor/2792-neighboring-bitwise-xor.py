class Solution:
    def doesValidArrayExist(self, derived: List[int]) -> bool:
        lastEl = 0
        for i in range(1, len(derived) + 1):
            theIndex = i % len(derived)
            lastEl = lastEl ^ derived[theIndex]
        return lastEl == 0