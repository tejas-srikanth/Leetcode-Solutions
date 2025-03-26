class Solution:
    def numOfUnplacedFruits(self, fruits: List[int], baskets: List[int]) -> int:
        isPlaced = 0
        for i in range(len(fruits)):
            for j in range(len(baskets)):
                if baskets[j] >= fruits[i]:
                    isPlaced += 1
                    baskets[j] = 0
                    break
        return len(fruits) - isPlaced
            