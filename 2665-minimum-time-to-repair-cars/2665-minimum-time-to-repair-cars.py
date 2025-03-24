class Solution:
    def maxCars(self, ranks, minutes):
        numCars = 0
        for rank in ranks:
            numCars += int((minutes // rank) ** (1/2))
        return numCars

    def repairCars(self, ranks: List[int], cars: int) -> int:
        lo = 0
        hi = cars**2 * sum(ranks)
        while lo < hi:
            mid = (lo + hi) // 2
            if (self.maxCars(ranks, mid) >= cars):
                hi = mid
            else:
                lo = mid + 1
        return lo