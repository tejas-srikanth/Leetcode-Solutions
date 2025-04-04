class Solution:
    def decodeString(self, s: str) -> str:
        s = "1[" + s + "]"
        tokenized = []
        currNum = 0
        currString = ""
        for i in range(len(s)):
            if s[i].isdigit():
                currNum *= 10
                currNum += int(s[i])
                if currString != "":
                    tokenized.append(currString)
                    currString = ""
            elif s[i] == "[":
                tokenized.append(currNum)
                tokenized.append(s[i])
                currNum = 0
            elif s[i] == "]":
                if currString != "":
                    tokenized.append(currString)
                    currString = ""
                tokenized.append(s[i])
            else:
                currString += s[i]
        currStack = []
        for i in range(len(tokenized)):
            if isinstance(tokenized[i], str) and tokenized[i] not in ["[", "]"]:
                currStack.append(tokenized[i])
            elif tokenized[i] == "[":
                currStack.append(tokenized[i])
            elif tokenized[i] == "]":
                currString = ""
                while currStack[-1] != "[":
                    currString = currStack.pop() + currString
                currStack.pop()
                numRepeat = currStack.pop()
                currStack.append(numRepeat * currString)
            else:
                currStack.append(tokenized[i])
        return currStack[0]
