class Solution:
    def dfs(self, graph, currStack, currNode, target):
        if currNode == target:
            return [currStack[:]]
        else:
            currSols = []
            for neighbour in graph[currNode]:
                currStack.append(neighbour)
                sols = self.dfs(graph, currStack, neighbour, target)
                currStack.pop()
                currSols += sols
            return currSols
            

    def allPathsSourceTarget(self, graph: List[List[int]]) -> List[List[int]]:
        return self.dfs(graph, [0], 0, len(graph)-1)