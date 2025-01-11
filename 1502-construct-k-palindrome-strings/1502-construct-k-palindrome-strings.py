class Solution:
    def canConstruct(self, s: str, k: int) -> bool:
        counter = [0 for i in range(26)]
        for i in range(len(s)):
            counter[ord(s[i]) - ord("a")] += 1
        oddGroups = 0
        evenGroups = 0
        for i in range(len(counter)):
            if counter[i] > 0 and counter[i] % 2 == 0:
                evenGroups += 1
            if counter[i] > 0 and counter[i] % 2 == 1:
                oddGroups += 1
        return oddGroups <= k and len(s) >= k