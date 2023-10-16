class Solution {
public:
    int jump(vector<int>& nums) {
        if (nums.size() == 1){
            return 0;
        }

        vector<int> dp(nums.size(), 10020);
        int k = nums.size();
        int currMin = 10020;
        dp[k-1] = 0;
        for (int i=nums.size() - 2; i>=0; --i){
            currMin = 10020;
            for (int j=i+1; j<=min(k-1, i+nums[i]); ++j){
                currMin = min(dp[j]+1, currMin);
            }
            dp[i] = currMin;
        }
        return dp[0];
    }
};