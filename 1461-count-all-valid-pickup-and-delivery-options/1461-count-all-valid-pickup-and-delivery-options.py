class Solution:

    def countOrders(self, n: int) -> int:
        MD = 1000000000 + 7
        if n == 1:
            return 1
        return ((2 * n) * (2 * n - 1) // 2) * self.countOrders(n-1) % MD