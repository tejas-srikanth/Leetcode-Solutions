from collections import deque
class Solution:
    def checkContradictions(self, equations: List[List[str]], values: List[float]) -> bool:
        theGraph = {}
        for i in range(len(equations)):
            if equations[i][0] not in theGraph:
                theGraph[equations[i][0]] = []
            if equations[i][1] not in theGraph:
                theGraph[equations[i][1]] = []
            theGraph[equations[i][0]].append((equations[i][1], values[i]))
            theGraph[equations[i][0]].append((equations[i][0], 1))
            theGraph[equations[i][1]].append((equations[i][1], 1))
        for var in theGraph:
            visited = {var: 1}
            q = deque()
            q.append((var, 1))
            while q:
                v, prod = q.popleft()
                for n in theGraph[v]:
                    if n[0] not in visited:
                        q.append((n[0], n[1] * prod))
                        visited[n[0]] = n[1] * prod
                    elif abs(n[1] * prod - visited[n[0]]) > 0.01:
                        return True
        return False
            

        