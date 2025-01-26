class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        unordered_map<int, int> um;
        int numEl = 0;
        int winStart = 0;
        int maxWin = 0;
        for (int i=0; i<nums.size(); ++i){
            if (um.find(nums[i]) == um.end()){
                um[nums[i]] = 0;
            }
            um[nums[i]]++;
            if (um[nums[i]] == k+1){
                numEl++;
            }

            if (numEl > 0){
                um[nums[winStart]] -= 1;
                if (um[nums[winStart]] == k){
                    numEl --;
                }
                winStart ++;
            }

            if (numEl == 0){
                maxWin = max(i - winStart + 1, maxWin);
            }
        }
        return maxWin;
    }
};