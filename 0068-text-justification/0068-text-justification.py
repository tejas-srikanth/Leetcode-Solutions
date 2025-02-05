class Solution:
    def fullJustify(self, words: List[str], maxWidth: int) -> List[str]:
        wordDict = []
        i = 0
        totalLength = 0
        currWord = []
        while i < len(words):
            while i < len(words) and totalLength + len(words[i]) + len(currWord) <= maxWidth:
                currWord.append(words[i])
                totalLength += len(words[i])
                i += 1
            isLast = i == len(words)
            newWord = ""
            numSpaces = maxWidth - totalLength
            if (len(currWord) == 1):
                newWord = currWord[0] + " " * numSpaces
                wordDict.append(newWord)
            else:
                spacePer = (numSpaces) // (len(currWord) - 1)
                numAddSpace = (numSpaces) % (len(currWord) - 1)
                if not isLast:
                    for j in range(len(currWord)-1):
                        newWord += currWord[j] + " " * spacePer
                        if (numAddSpace > 0):
                            newWord += " "
                            numAddSpace -= 1
                    newWord += currWord[-1]
                    wordDict.append(newWord)
                else:
                    for j in range(len(currWord)-1):
                        newWord += currWord[j]
                        newWord += " "
                        numSpaces -= 1
                    newWord += currWord[-1]
                    newWord += " " * numSpaces
                    wordDict.append(newWord)
            currWord = []
            totalLength = 0
        return wordDict


        

            