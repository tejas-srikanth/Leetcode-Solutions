class Solution:
    def compressedString(self, word: str) -> str:
        comp = ""
        currChar = word[0]
        currCnt = 1
        for i in range(1, len(word)):
            if word[i] == word[i-1]:
                currCnt += 1
            else:
                if currCnt > 0:
                    comp += str(currCnt) + currChar
                currChar = word[i]
                currCnt = 1

            if currCnt == 9:
                comp += str(currCnt) + currChar
                currCnt = 0

        if currCnt > 0:
            comp += str(currCnt) + currChar
        return comp
