class dsu:
    def __init__(self, n):
        self.ranks = [0] * n
        self.parent = [i for i in range(n)]
        self.totalWeight = [~(n & 0) for i in range(n)]
    
    def find(self, n):
        currNode = n
        if self.parent[currNode] != currNode:
            self.parent[currNode] = self.find(self.parent[currNode])
        return self.parent[currNode]
    
    def getWeight(self, n, m):
        parentN = self.find(n)
        parentM = self.find(m)
        if (parentM != parentN):
            return -1
        else:
            return self.totalWeight[parentN]
    
    def unite(self, n, m, weight):
        print(n, m)
        parentN = self.find(n)
        parentM = self.find(m)
        if (parentN == parentM):
            self.totalWeight[parentN] = self.totalWeight[parentN] & weight
            return True
        
        if (self.ranks[parentN] == self.ranks[parentM]):
            self.ranks[parentN] = self.ranks[parentM] + 1
            self.totalWeight[parentN] = self.totalWeight[parentN] & weight & self.totalWeight[parentM]
            self.parent[parentM] = parentN
        elif (self.ranks[parentN] > self.ranks[parentM]):
            self.totalWeight[parentN] = self.totalWeight[parentN] & weight & self.totalWeight[parentM]
            self.parent[parentM] = parentN
        else:
            self.totalWeight[parentM] = self.totalWeight[parentM] & weight & self.totalWeight[parentN]
            self.parent[parentN] = parentM
        return False


class Solution:
    def minimumCost(self, n: int, edges: List[List[int]], query: List[List[int]]) -> List[int]:
        dis = dsu(n)
        for edge in edges:
            dis.unite(edge[0], edge[1], edge[2])
        ans = []
        print(dis.totalWeight)
        for q in query:
            ans.append(dis.getWeight(q[0], q[1]))
        return ans

        