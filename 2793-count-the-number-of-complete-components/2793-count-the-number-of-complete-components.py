class DSU:
    def __init__(self, n):
        self.parent = [i for i in range(n)]
        self.ranks = [0 for i in range(n)]
        self.numEdges = [0 for i in range(n)]
    
    def find(self, n):
        if self.parent[n] != n:
            self.parent[n] = self.find(self.parent[n])
        return self.parent[n]
    
    def unite(self, n, m):
        parentN = self.find(n)
        parentM = self.find(m)
        if parentN == parentM:
            self.numEdges[parentN] += 1
            return True
        
        if self.ranks[parentM] == self.ranks[parentN]:
            self.ranks[parentM] = self.ranks[parentN] + 1
            self.parent[parentN] = parentM
            self.numEdges[parentM] = self.numEdges[parentN] + self.numEdges[parentM] + 1
        elif self.ranks[parentM] > self.ranks[parentN]:
            self.parent[parentN] = parentM
            self.numEdges[parentM] = self.numEdges[parentN] + self.numEdges[parentM] + 1
        else:
            self.parent[parentM] = parentN
            self.numEdges[parentN] = self.numEdges[parentN] + self.numEdges[parentM] + 1
        return False

class Solution:
    def countCompleteComponents(self, n: int, edges: List[List[int]]) -> int:
        dsu = DSU(n)
        for edge in edges:
            dsu.unite(edge[0], edge[1])
        d = {}
        for i in range(n):
            p = dsu.find(i)
            if p not in d:
                d[p] = 0
            d[p] += 1
        components = 0
        for p in d:
            if dsu.numEdges[p] == d[p] * (d[p] - 1) // 2:
                components += 1
        return components