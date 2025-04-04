from heapq import heapify, heappush, heappop
class Solution:
    def findMinArrowShots(self, points: List[List[int]]) -> int:
        points.sort()
        intStack = []
        h = []
        heapify(h)
        numArrows = 1
        for intvl in points:
            if len(h) == 0 or h[0][0] >= intvl[0]:
                heappush(h, (intvl[1], intvl[0]))
            else:
                numArrows += 1
                h = []
                heapify(h)
                heappush(h, (intvl[1], intvl[0]))
        return numArrows