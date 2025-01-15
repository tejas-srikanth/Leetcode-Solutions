class Trie:
    def __init__(self):
        self.children = [None for i in range(27)]
        self.word = ""
    
class Solution:
    def addWord(self, trie, word):
        currNode = trie
        for c in word:
            if currNode.children[ord(c) - ord("a")] is None:
                currNode.children[ord(c) - ord("a")] = Trie()
            currNode = currNode.children[ord(c) - ord("a")]
        currNode.children[26] = Trie()
        currNode.children[26].word = word
    
    def wordBreakHelper(self, s, theTrie):
        allSolutions = []
        currNode = theTrie
        if s == "":
            return [""]
        for i in range(len(s)):
            currNode = currNode.children[ord(s[i]) - ord("a")]
            if currNode is None:
                break
            if currNode.children[26] is not None:
                word = currNode.children[26].word
                ns = self.wordBreakHelper(s[i+1:], theTrie)
                newSols = []
                for j in range(len(ns)):
                    if ns[j] != "":
                        newSols.append(word + " " + ns[j])
                    else:
                        newSols.append(word)
                allSolutions += newSols
        return allSolutions
        
    def wordBreak(self, s: str, wordDict: List[str]) -> List[str]:
        theTrie = Trie()
        for w in wordDict:
            self.addWord(theTrie, w)
        arr = self.wordBreakHelper(s, theTrie)
        return arr
        