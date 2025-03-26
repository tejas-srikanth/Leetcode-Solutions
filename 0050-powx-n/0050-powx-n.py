class Solution:
    def intToBits(self, x):
        bitString = ""
        while x > 0:
            bitString += str(x % 2)
            x = x // 2
        return bitString[::-1]

    def myPow(self, x: float, n: int) -> float:
        if n < 0:
            n = -1 * n
            x = 1 / x
        binString = self.intToBits(n)
        currProd = 1
        for dig in binString:
            currProd = currProd * currProd
            if dig == "1":
                currProd *= x
        return currProd

        
        