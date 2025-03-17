"""
# Definition for an Interval.
class Interval:
    def __init__(self, start: int = None, end: int = None):
        self.start = start
        self.end = end
"""

class Solution:
    def placeInSorted(self, int1, int2):
        int1Ptr = 0
        int2Ptr = 0
        allIntervals = []
        while int1Ptr < len(int1) or int2Ptr < len(int2):
            if int1Ptr >= len(int1):
                allIntervals.append(int2[int2Ptr])
                int2Ptr += 1
            elif int2Ptr >= len(int2):
                allIntervals.append(int1[int1Ptr])
                int1Ptr += 1
            else:
                if int1[int1Ptr].start < int2[int2Ptr].start:
                    allIntervals.append(int1[int1Ptr])
                    int1Ptr += 1
                else:
                    allIntervals.append(int2[int2Ptr])
                    int2Ptr += 1
        return allIntervals

    def mergeIntervals(self, int1, int2):
        intStack = []
        int1 = self.placeInSorted(int1, int2)
        for i in int1:
            if len(intStack) == 0:
                intStack.append(i)
            else:
                x = intStack[-1]
                if x.end < i.start:
                    intStack.append(i)
                else:
                    intStack[-1].end = max(i.end, intStack[-1].end)
        return intStack

    def employeeFreeTime(self, schedule: '[[Interval]]') -> '[Interval]':
        bestIntervals = schedule[0]
        for i in range(1, len(schedule)):
            bestIntervals = self.mergeIntervals(bestIntervals, schedule[i])
        intvls = []
        for i in range(len(bestIntervals)-1):
            intvls.append(Interval(bestIntervals[i].end, bestIntervals[i + 1].start))
        return intvls

        
        