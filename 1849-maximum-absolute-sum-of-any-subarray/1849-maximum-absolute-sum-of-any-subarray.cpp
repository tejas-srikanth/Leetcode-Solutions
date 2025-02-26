class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int maxSum = 0;
        int minSum = 0;
        int currSum = 0;
        int bestSum = 0;
        for (int i=0; i<nums.size(); ++i){
            currSum += nums[i];
            bestSum = max({bestSum, abs(currSum - maxSum), abs(currSum - minSum)});
            maxSum = max(maxSum, currSum);
            minSum = min(minSum, currSum);
        }
        return bestSum;
    }
};