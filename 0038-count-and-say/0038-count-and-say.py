class Solution:
    def countAndSay(self, n: int) -> str:
        rle = "1"
        for i in range(n-1):
            thing = ""
            numCons = 1
            for j in range(1, len(rle)):
                if rle[j] == rle[j-1]:
                    numCons += 1
                else:
                    thing += str(numCons)
                    thing += rle[j-1]
                    numCons = 1
            thing += str(numCons)
            thing += rle[-1]
            rle = thing
        return rle
        