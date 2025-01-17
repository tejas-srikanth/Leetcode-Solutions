from collections import deque
from heapq import heapify, heappush, heappop
class Solution:
    def getKth(self, lo: int, hi: int, k: int) -> int:
        sortedInts = []
        for i in range(lo, hi + 1):
            j = i
            numSteps = 0
            while j != 1:
                if j % 2 == 1:
                    j *= 3
                    j += 1
                else:
                    j //= 2
                numSteps += 1
            sortedInts.append((numSteps, i))
            
        sortedInts.sort()
        return sortedInts[k-1][1]
        