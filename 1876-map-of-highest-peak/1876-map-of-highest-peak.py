from collections import deque
class Solution:
    def highestPeak(self, isWater: List[List[int]]) -> List[List[int]]:
        q = deque()
        m, n = len(isWater), len(isWater[0])
        visited = [[False for i in range(n)] for j in range(m)]
        for i in range(len(isWater)):
            for j in range(len(isWater[0])):
                if isWater[i][j] == 1:
                    q.append((i, j, 0))
                    visited[i][j] = True
        dirs = [(1, 0), (-1, 0), (0, -1), (0, 1)]
        currCost = 0
        while q:
            r, c, cost = q.popleft()
            isWater[r][c] = cost
            for dr in dirs:
                rn, cn = r + dr[0], c + dr[1]
                if rn >= 0 and rn < m and cn >= 0 and cn < n and not visited[rn][cn]:
                    visited[rn][cn] = True
                    q.append((rn, cn, cost + 1))
        return isWater
