from collections import deque
class Solution:
    def shortestDistance(self, grid: List[List[int]]) -> int:
        distances = [[0 for i in range(len(grid[0]))] for j in grid]
        dirs = [(0, 1), (0, -1), (1, 0), (-1, 0)]
        for i in range(len(grid)):
            for j in range(len(grid[0])):
                if grid[i][j] == 1:
                    mindist = [[float("inf") for i in range(len(grid[0]))] for j in grid]
                    mindist[i][j] = 0
                    q = deque()
                    q.append(((i, j), 0))
                    while q:
                        co, dist = q.popleft()
                        r, c = co
                        for dr, dc in dirs:
                            nr = r + dr
                            nc = c + dc
                            if nr >= 0 and nr < len(grid) and nc >= 0 and nc < len(grid[0]) and grid[nr][nc] == 0 and mindist[nr][nc] == float("inf"):
                                q.append(((nr, nc), dist + 1))
                                mindist[nr][nc] = dist + 1
                    for k in range(len(distances)):
                        for m in range(len(distances[0])):
                            distances[k][m] += mindist[k][m]
        mn = float("inf")
        for i in range(len(distances)):
            for j in range(len(distances[0])):
                if grid[i][j] == 0:
                    mn = min(mn, distances[i][j])
        if mn == float("inf"):
            return -1
        return mn
                        