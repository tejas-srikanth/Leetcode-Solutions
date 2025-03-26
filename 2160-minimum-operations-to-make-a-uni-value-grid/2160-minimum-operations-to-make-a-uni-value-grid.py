class Solution:
    def minOperations(self, grid: List[List[int]], x: int) -> int:
        flattened = [x for xs in grid for x in xs]
        flattened.sort()
        if len(flattened) == 1:
            return 0
        med = flattened[(len(flattened)) // 2]
        numOps = 0
        for i in range(len(grid)):
            for j in range(len(grid[i])):
                if grid[i][j] % x != med % x:
                    return -1
                else:
                    numOps += abs(grid[i][j] - med) // x
        return numOps
