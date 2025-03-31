from heapq import heapify, heappop, heappush
from bisect import bisect_left
class Solution:
    def maxPoints(self, grid: List[List[int]], queries: List[int]) -> List[int]:
        dirs = [(1, 0), (-1, 0), (0, -1), (0, 1)]
        h = []
        heapify(h)
        heappush(h, (grid[0][0], (0, 0)))
        points = [(grid[0][0], 0)]
        visited = [[False for i in range(len(grid[0]))] for j in range(len(grid))]
        visited[0][0] = True
        while len(h) > 0:
            currMax, x = heappop(h)
            r, c = x
            if grid[r][c] <= points[-1][0]:
                points[-1] = ((points[-1][0], points[-1][1] + 1))
            else:
                points.append((grid[r][c], points[-1][1] + 1))
            for dr in dirs:
                nr, nc = r + dr[0], c + dr[1]
                if (nr >= 0 and nr < len(grid) and nc >= 0 and nc < len(grid[0]) and not visited[nr][nc]):
                    visited[nr][nc] = True
                    heappush(h, (max(grid[nr][nc], currMax), (nr, nc)))
        ans = []
        for q in queries:
            ind = bisect_left(points, (q, -float("inf")))
            if ind == 0:
                ans.append(0)
            else:
                ans.append(points[ind-1][1])
        return ans

            
        