class Solution:
    def countSetBits(self, num):
        csb = 0
        while num > 0:
            csb += num % 2
            num = num // 2
        return csb 

    def revBits(self, n1, leadZeros):
        currNum = 0
        while n1 > 0:
            currNum *= 2
            currNum += n1%2
            n1 = n1 // 2
        for i in range(leadZeros):
            currNum *= 2
        return currNum

    def minimizeXor(self, num1: int, num2: int) -> int:
        x1 = self.countSetBits(num1)
        x2 = self.countSetBits(num2)
        print(x1, x2)
        if x2 > x1:
            currNum = 0
            numZerosFound = x2 - x1
            n1 = num1
            while n1 > 0 or numZerosFound > 0:
                currNum *= 2
                leadZeros = 0
                if n1%2 == 0 and numZerosFound > 0:
                    currNum += 1
                    numZerosFound -= 1
                elif n1%2 == 1:
                    currNum += 1
                elif currNum == 0:
                    leadZeros += 1
                n1 = n1 // 2
            return self.revBits(currNum, leadZeros)
        else:
            currNum = 0
            n1 = num1
            leadZeros = 0
            numOnes = 0
            while n1 > 0:
                currNum *= 2
                if n1%2 == 1:
                    numOnes += 1
                if numOnes > x1 - x2 and n1%2 == 1:
                    currNum += 1
                elif currNum == 0:
                    leadZeros += 1
                n1 = n1 // 2
            return self.revBits(currNum, leadZeros)


            