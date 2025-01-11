class Solution:
    def wordSubsets(self, words1: List[str], words2: List[str]) -> List[str]:
        words1copy = words1[:]
        for i in range(len(words1)):
            arr = [0 for i in range(26)]
            for c in words1[i]:
                arr[ord(c) - ord("a")] += 1
            words1[i] = arr

        words2arr = [0 for i in range(26)]
        for i in range(len(words2)):
            arr = [0 for j in range(26)]
            for c in words2[i]:
                arr[ord(c) - ord("a")] += 1
            for j in range(26):
                words2arr[j] = max(arr[j], words2arr[j])
            
        
        universal = []
        for i in range(len(words1)):
            w1 = words1[i]
            w2 = words2arr
            isUniversal = True
            for k in range(26):
                if w2[k] > w1[k]:
                    isUniversal = False
                    break
            if isUniversal:
                universal.append(words1copy[i])

        return universal