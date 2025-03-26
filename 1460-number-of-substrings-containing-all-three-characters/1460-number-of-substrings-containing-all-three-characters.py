class Solution:
    def numberOfSubstrings(self, s: str) -> int:
        lastA = -1
        lastB = -1
        lastC = -1
        total = 0
        for i in range(len(s)):
            if s[i] == 'a':
                lastA = i
            elif s[i] == 'b':
                lastB = i
            else:
                lastC = i
            if min(lastA, lastB, lastC) != -1:
                total += min(lastA, lastB, lastC) + 1
        return total