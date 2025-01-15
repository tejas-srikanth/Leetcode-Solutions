class Solution:
    def dfs(self, theGraph, currNode, visited, recStack, toporder):
        visited[currNode] = True
        for neighbour in theGraph[currNode]:
            if recStack[neighbour]:
                return -1
            elif not visited[neighbour]:
                recStack[neighbour] = True
                out = self.dfs(theGraph, neighbour, visited, recStack, toporder)
                recStack[neighbour] = False
                if out == -1:
                    return -1
        toporder.append(currNode)
        return 0
    
    def getTopOrder(self, theGraph, n):
        visited = [False for i in range(n)]
        recStack = [False for i in range(n)]
        toporder = []
        for i in range(n):
            if not visited[i]:
                recStack[i] = True
                out = self.dfs(theGraph, i, visited, recStack, toporder)
                recStack[i] = False
                if out == -1:
                    return []
        return toporder
        

    def buildMatrix(self, k: int, rowConditions: List[List[int]], colConditions: List[List[int]]) -> List[List[int]]:
        rowGraph = [[] for i in range(k)]
        colGraph = [[] for i in range(k)]
        for rc in rowConditions:
            print(rc)
            rowGraph[rc[0]-1].append(rc[1]-1)
        for cc in colConditions:
            colGraph[cc[0]-1].append(cc[1]-1)
        toporderRow = self.getTopOrder(rowGraph, k)
        toporderCol = self.getTopOrder(colGraph, k)
        if toporderRow == [] or toporderCol == []:
            return []
        matrix = [[0 for i in range(k)] for j in range(k)]
        d = {}
        for i in range(len(toporderRow)-1, -1, -1):
            d[toporderRow[i]] = k - i - 1
        for j in range(len(toporderCol)-1, -1, -1):

            matrix[d[toporderCol[j]]][k - j - 1] = toporderCol[j] + 1
        return matrix
        