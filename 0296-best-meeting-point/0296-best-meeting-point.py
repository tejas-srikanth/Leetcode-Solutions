class Solution:
    def findBestDistance(self, sums):
        
        if len(sums) == 1:
            return 0
        
        prefixSums = [sums[0]]
        currPrefixSum = sums[0]
        
        for i in range(1, len(sums)):
            currPrefixSum += sums[i]
            prefixSums.append(currPrefixSum)
            
        suffixSums = [sums[-1]]
        currSuffixSum = sums[-1]
        for i in range(len(sums)-2, -1, -1):
            currSuffixSum += sums[i]
            suffixSums.append(currSuffixSum)
        suffixSums.reverse()
        
        currDist = sum([i * sums[i] for i in range(len(sums))])
        bestInd = 0
        bestDist = currDist
        for i in range(1, len(sums)):
            currDist += prefixSums[i-1]
            currDist -= suffixSums[i]
            bestDist = min(bestDist, currDist)
                
        return bestDist
        
    def minTotalDistance(self, grid: List[List[int]]) -> int:
        rowSums = [sum(i) for i in grid]
        colSums = [sum([grid[i][j] for i in range(len(grid))]) for j in range(len(grid[0]))]
        return self.findBestDistance(rowSums) + self.findBestDistance(colSums)
        