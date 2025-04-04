from heapq import heapify, heappop, heappush
class Solution:
    def maxScore(self, nums1: List[int], nums2: List[int], k: int) -> int:
        theArr = [(nums2[i], nums1[i]) for i in range(len(nums1))]
        theArr.sort()
        h = []
        heapify(h)
        numTotal = 0
        best = -float("inf")
        for i in range(len(theArr)-1, -1, -1):
            if len(h) < k - 1:
                heappush(h, theArr[i][1])
                numTotal += theArr[i][1]
            elif len(h) == k - 1:
                heappush(h, theArr[i][1])
                numTotal += theArr[i][1]
                best = max(best, numTotal * theArr[i][0])
            elif len(h) == k:
                out = h[0]
                if out < theArr[i][1]:
                    heappop(h)
                    heappush(h, theArr[i][1])
                    numTotal += (theArr[i][1] - out)
                    best = max(best, numTotal * theArr[i][0])
        return best

