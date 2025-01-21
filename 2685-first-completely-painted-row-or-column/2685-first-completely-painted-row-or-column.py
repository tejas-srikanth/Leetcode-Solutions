class Solution:
    def firstCompleteIndex(self, arr: List[int], mat: List[List[int]]) -> int:
        rowCounts = [len(mat[0]) for i in range(len(mat))]
        colCounts = [len(mat) for i in range(len(mat[0]))]
        d = {}
        for i in range(len(mat)):
            for j in range(len(mat[0])):
                d[mat[i][j]] = (i, j)
        for i in range(len(arr)):
            a, b = d[arr[i]]
            rowCounts[a] -= 1
            colCounts[b] -= 1
            if rowCounts[a] == 0 or colCounts[b] == 0:
                return i
        return -1

