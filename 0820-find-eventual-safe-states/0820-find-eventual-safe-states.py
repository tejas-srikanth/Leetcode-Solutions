from collections import deque
class Solution:
    def eventualSafeNodes(self, graph: List[List[int]]) -> List[int]:
        reverseGraph = [[] for i in range(len(graph))]
        for i in range(len(graph)):
            lst = graph[i]
            for n in lst:
                reverseGraph[n].append(i)
        q = deque()
        visited = [False for i in range(len(graph))]
        for i in range(len(graph)):
            if len(graph[i]) == 0:
                q.append(i)
                visited[i] = True
        while q:
            newelt = q.popleft()
            for n in reverseGraph[newelt]:
                if not visited[n] and all([visited[j] for j in graph[n]]):
                    q.append(n)
                    visited[n] = True
        allSafe = []
        for i in range(len(visited)):
            if visited[i] == True:
                allSafe.append(i)
        return allSafe
        