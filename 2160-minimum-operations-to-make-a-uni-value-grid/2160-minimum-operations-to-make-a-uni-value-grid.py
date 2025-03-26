class Solution:
    def minOperations(self, grid: List[List[int]], x: int) -> int:
        flattened = [x for xs in grid for x in xs]
        flattened.sort()
        if len(flattened) == 1:
            return 0
        med = flattened[(len(flattened)) // 2]
        numOps = 0
        for elt in flattened:
            if elt % x != med % x:
                return -1
            else:
                numOps += abs(elt - med) // x
        return numOps
