class Solution:
    def countServers(self, grid: List[List[int]]) -> int:
        rowCounts = [sum(i) for i in grid]
        colCounts = [sum([grid[i][j] for i in range(len(grid))]) for j in range(len(grid[0]))]
        numConnected = 0
        for i in range(len(grid)):
            for j in range(len(grid[0])):
                if grid[i][j] == 1:
                    if rowCounts[i] > 1:
                        numConnected += 1
                    elif colCounts[j] > 1:
                        numConnected += 1
        return numConnected
