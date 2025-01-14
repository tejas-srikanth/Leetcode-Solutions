class Solution:
    def minimumLength(self, s: str) -> int:
        alphabetCount = [0 for i in range(26)]
        for i in range(len(s)):
            alphabetCount[ord(s[i]) - ord("a")] += 1
        lenFinal = 0
        for i in range(len(alphabetCount)):
            if alphabetCount[i] > 0:
                if alphabetCount[i] <= 2:
                    lenFinal += alphabetCount[i]
                else:
                    lenFinal += (2 - alphabetCount[i] % 2)
        return lenFinal
