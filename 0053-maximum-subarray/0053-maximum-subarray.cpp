class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int minSum = 0;
        int max = -1;
        int rolling = 0;
        for (int i=0; i<nums.size(); ++i){
            rolling += nums[i];
            if (rolling - minSum > max || i == 0){
                max = rolling - minSum;
            }

            if (rolling < minSum){
                minSum = rolling;
            }
        }
        return max;
    }
};