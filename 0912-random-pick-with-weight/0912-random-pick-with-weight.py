import random
from bisect import bisect_left
class Solution:

    def __init__(self, w: List[int]):
        self.w = w
        self.w_sum = sum(w)
        self.x = []
        currSum = 0
        for i in range(len(w)):
            currSum += w[i]
            self.x.append(currSum)
        

    def pickIndex(self) -> int:
        currentSum = self.w_sum * random.random()
        ind = bisect_left(self.x, currentSum)
        return ind



# Your Solution object will be instantiated and called as such:
# obj = Solution(w)
# param_1 = obj.pickIndex()