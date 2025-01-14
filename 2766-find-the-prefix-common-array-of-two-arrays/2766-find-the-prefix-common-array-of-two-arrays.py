class Solution:
    def findThePrefixCommonArray(self, A: List[int], B: List[int]) -> List[int]:
        numArray = [0 for i in range(len(A))]
        numElements = 0
        res = []
        for i in range(len(A)):
            numArray[A[i] - 1] += 1
            numArray[B[i] - 1] += 1
            if numArray[A[i] - 1] == 2:
                numElements += 1
            if numArray[B[i] - 1] == 2:
                numElements += 1
            if A[i] - 1 == B[i] - 1:
                numElements -= 1
            res.append(numElements)
        return res

        