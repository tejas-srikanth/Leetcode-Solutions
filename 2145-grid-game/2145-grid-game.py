class Solution:
    def gridGame(self, grid: List[List[int]]) -> int:
        pref = 0
        suf = 0
        largest = float("inf")
        for i in range(len(grid[0])):
            pref += grid[1][i]
        for i in range(len(grid[0])-1, -1, -1):
            pref -= grid[1][i]
            largest = min(largest, max(pref, suf))
            suf += grid[0][i]
        return largest