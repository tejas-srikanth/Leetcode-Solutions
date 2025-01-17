from bisect import bisect_right
class Solution:
    def searchMatrix(self, matrix: List[List[int]], target: int) -> bool:
        x = []
        for i in range(len(matrix)):
            x.append(matrix[i][0])
        ind = bisect_right(x, target)
        if ind == 0:
            return False
        for i in range(ind):
            searchRow = matrix[i]
            indFinal = bisect_right(searchRow, target)

            if matrix[i][indFinal-1] == target:
                return True
        return False