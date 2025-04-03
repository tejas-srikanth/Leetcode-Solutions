from heapq import heapify, heappop, heappush
class SmallestInfiniteSet:

    def __init__(self):
        self.h = []
        heapify(self.h)
        self.currAdded = {}
        self.smallest = 1

    def popSmallest(self) -> int:
        if len(self.h) == 0:
            self.smallest += 1
            return self.smallest - 1
        else:
            out = heappop(self.h)
            del self.currAdded[out]
            return out

    def addBack(self, num: int) -> None:
        if num < self.smallest and num not in self.currAdded:
            self.currAdded[num] = 1
            heappush(self.h, num)
        


# Your SmallestInfiniteSet object will be instantiated and called as such:
# obj = SmallestInfiniteSet()
# param_1 = obj.popSmallest()
# obj.addBack(num)