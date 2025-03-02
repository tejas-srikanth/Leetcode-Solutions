from collections import deque
class Solution:
    def dfs(self, theGraph, visited, currNode, recStack, tgt):
        visited[currNode] = True
        if (currNode == tgt):
            return True
        else:
            for neighbour in theGraph[currNode]:
                if not visited[neighbour]:
                    recStack.append(neighbour)
                    if self.dfs(theGraph, visited, neighbour, recStack, tgt):
                        return True
                    recStack.pop()
            return False

    def mostProfitablePath(self, edges: List[List[int]], bob: int, amount: List[int]) -> int:
        n = len(amount)
        theGraph = [[] for i in range(n)]
        for edge in edges:
            theGraph[edge[0]].append(edge[1])
            theGraph[edge[1]].append(edge[0])
        recStack = [0]
        visited = [False for i in range(n)]
        self.dfs(theGraph, visited, 0, recStack, bob)
        a = 0
        b = len(recStack)-1
        totalBobRewards = 0
        while (a < b):
            amount[recStack[b]] = 0
            b -= 1
            a += 1
        if a == b:
            amount[recStack[b]] //= 2
        print(totalBobRewards)
        q = deque()
        visited = [False for i in range(n)]
        q.append((0, amount[0]))
        visited[0] = True
        bestIncome = -float("inf")
        while q:
            currNode, currAmount = q.popleft()
            if len(theGraph[currNode]) == 1 and currNode != 0:
                bestIncome = max(bestIncome, currAmount)

            for neighbour in theGraph[currNode]:
                if not visited[neighbour]:
                    visited[neighbour] = True
                    q.append((neighbour, currAmount + amount[neighbour]))
        return bestIncome