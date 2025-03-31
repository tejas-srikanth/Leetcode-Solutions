from heapq import heapify, heappop, heappush
class Solution:
    def putMarblesHelper(self, weights, k, sign):
        h = []
        for i in range(len(weights)-1):
            h.append(sign * (weights[i] + weights[i + 1]))
        h.sort()        
        return sign * (sum(h[:k-1]))

    def putMarbles(self, weights: List[int], k: int) -> int:
        return self.putMarblesHelper(weights, k, -1) - self.putMarblesHelper(weights, k, 1)
