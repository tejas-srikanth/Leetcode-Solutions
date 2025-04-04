from bisect import bisect_right
class Solution:
    def successfulPairs(self, spells: List[int], potions: List[int], success: int) -> List[int]:
        multiplier = []
        for i in range(len(potions)):
            multiplier.append((success + potions[i] - 1) // potions[i])
        multiplier.sort()
        res = []
        for i in range(len(spells)):
            ind = bisect_right(multiplier, spells[i])
            res.append(ind)
        return res