class Solution:
    def doesValidArrayExist(self, derived: List[int]) -> bool:
        lastEl = 0
        for i in range(len(derived)):
            lastEl = lastEl ^ derived[i]
        return lastEl == 0