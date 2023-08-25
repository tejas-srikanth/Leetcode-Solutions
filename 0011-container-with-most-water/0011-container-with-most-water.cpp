class Solution {
public:


    int maxArea(vector<int>& height) {
        int currMax = -1;
        int s = 0; int e = height.size() - 1;
        int contW = 0;
        while (s <= e){
            contW = (e - s) * min(height[e], height[s]);
            if (contW > currMax){
                currMax = contW;
            }

            if (height[s] < height[e]){
                s++;
            } else {
                e--;
            }
        }
        return currMax;
        
    }
};