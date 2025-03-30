class Solution:
    def partitionLabels(self, s: str) -> List[int]:
        allIntervals = [[-1, -1] for i in range(26)]
        for i in range(len(s)):
            c = s[i]
            if allIntervals[ord(c) - ord('a')][0] == -1:
                allIntervals[ord(c) - ord('a')] = [i, i]
            else:
                allIntervals[ord(c) - ord('a')][-1] = i
        newIntervals = []
        for intvl in allIntervals:
            if intvl[0] != -1:
                newIntervals.append(intvl)
        newIntervals.sort()
        mergedInts = []
        for intvl in newIntervals:
            if len(mergedInts) == 0 or mergedInts[-1][-1] < intvl[0]:
                mergedInts.append(intvl)
            else:
                mergedInts[-1][1] = max(mergedInts[-1][1], intvl[1])
        return [i[1] - i[0] +1 for i in mergedInts]