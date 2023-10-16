class Solution {
public:
    bool canJump(vector<int>& nums) {
        int lastValidIndex = nums.size() - 1;
        bool dp[nums.size()];
        dp[nums.size() - 1] = 1;
        for (int i=nums.size() - 1; i>=0; --i){
            if (lastValidIndex - i <= nums[i]){
                dp[i] = 1;
                lastValidIndex = i;
            } else {
                dp[i] = 0;
            }
        }
        return dp[0];
    }
};