class Solution {
public:
    int rob(vector<int>& nums) {
        vector<int> dp(nums.size(), 0);
        int numIt = 0;
        for (int i=nums.size() - 1; i >=0; --i){
            numIt++;
            if (numIt == 1){
                dp[i] = nums[i];
            } else if (numIt == 2){
                dp[i] = max(nums[i], dp[i+1]);
            } else {
                dp[i] = max(nums[i] + dp[i+2], dp[i+1]);
            }
        }
        return dp[0];
    }
};