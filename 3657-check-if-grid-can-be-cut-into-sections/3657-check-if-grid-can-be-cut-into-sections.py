class Solution:
    def checkValidCuts(self, n: int, rectangles: List[List[int]]) -> bool:
        intvlsX = []
        intvlsY = []
        for i, intvls in enumerate([intvlsX, intvlsY]):
            if i == 1:
                rectangles = [[i[1], i[0], i[3], i[2]] for i in rectangles]
            rectangles.sort()
            for rect in rectangles:
                if len(intvls) == 0 or intvls[-1][1] <= rect[0]:
                    intvls.append([rect[0], rect[2]])
                else:
                    intvls[-1][1] = max(intvls[-1][1], rect[2])
        return max(len(intvlsX), len(intvlsY)) > 2
            