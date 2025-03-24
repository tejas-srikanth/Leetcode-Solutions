class Solution:
    def countDays(self, days: int, meetings: List[List[int]]) -> int:
        meetings.sort()
        intStack = []
        for intvl in meetings:
            if len(intStack) > 0 and intvl[0] <= intStack[-1][1]:
                intStack[-1][1] = max(intvl[1], intStack[-1][1])
            else:
                intStack.append(intvl)
        intStack.append([days + 1, float("inf")])
        currStart = 0
        numDays = 0
        for i in range(len(intStack)):
            intvl = intStack[i]
            numDays += max(intvl[0] - currStart - 1, 0)
            currStart = intvl[1]
        return numDays
        