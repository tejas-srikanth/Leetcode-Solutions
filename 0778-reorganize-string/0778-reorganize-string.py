from heapq import heapify, heappop, heappush
class Solution:
    def reorganizeString(self, s: str) -> str:
        allChars = [0 for i in range(26)]
        for i in range(len(s)):
            allChars[ord(s[i]) - ord('a')] += 1
        newS = ""
        i = len(s)
        h = []
        heapify(h)
        for i in range(len(allChars)):
            if allChars[i] > 0:
                heappush(h, (-allChars[i], chr(ord('a') + i)))

        isValid = True
        while len(h) > 0:
            cnt, char = heappop(h)
            if len(newS) > 0 and char == newS[-1]:
                if len(h) == 0:
                    return ""
                oldcnt, oldchar = cnt, char
                cnt, char = heappop(h)
                heappush(h, (oldcnt, oldchar))
            newS += char
            cnt += 1
            if cnt < 0:
                heappush(h, (cnt, char))

        if len(s) != len(newS):
            return ""

        return newS

