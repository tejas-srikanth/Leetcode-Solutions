class Solution {
    fun maxArea(height: IntArray): Int {
        var stPtr = 0
        var eptr = height.size - 1
        var currArea = 0
        while (stPtr < eptr){
            currArea = max(currArea, min(height[stPtr], height[eptr]) * (eptr - stPtr))
            if (height[stPtr] < height[eptr]){
                while (stPtr < height.size && height[stPtr] < height[eptr]){
                    currArea = max(currArea, min(height[stPtr], height[eptr]) * (eptr - stPtr))
                    stPtr += 1
                }
            } else {
                while (eptr >= 0 && height[eptr] <= height[stPtr]){
                    currArea = max(currArea, min(height[stPtr], height[eptr]) * (eptr - stPtr))
                    eptr -= 1
                }
            }
        }
        return currArea
    }
}