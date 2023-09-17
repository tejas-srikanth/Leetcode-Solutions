class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int prevO = -1;
        int currO = 0;
        int maxSum = -1;
        for (int x: nums){
            if (x == 1){
                currO++;
            } else if (x == 0){
                    maxSum = max({prevO + currO, currO, maxSum});
                    prevO = currO;
                    currO = 0;
            }
        }
        if (prevO == -1){
            return currO - 1;
        } else {
            return max(maxSum, prevO + currO);
        }
    }
};