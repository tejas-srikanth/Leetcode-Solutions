from heapq import heappop, heappush, heapify
class Solution:
    def maxPerformance(self, n: int, speed: List[int], efficiency: List[int], k: int) -> int:
        arr = [(efficiency[i], speed[i]) for i in range(len(speed))]
        arr.sort()
        arr = list(reversed(arr))
        minHeap = []
        heapify([])
        totalSpeed = 0
        bestEfficiency = -1
        MOD = 1000000000 + 7
        for i in range(k):
            heappush(minHeap, arr[i][1])
            totalSpeed += arr[i][1]
            bestEfficiency = max(bestEfficiency, totalSpeed * arr[i][0])
        for i in range(k, n):
            worstSpeed = minHeap[0]
            if worstSpeed < arr[i][1]:
                heappop(minHeap)
                heappush(minHeap, arr[i][1])
                totalSpeed += (arr[i][1] - worstSpeed)
                bestEfficiency = max(bestEfficiency, totalSpeed * arr[i][0])
        return bestEfficiency % MOD
            
        
