class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        vector<int> prefArray = {0};
        for (int i=0; i<nums.size(); ++i){
            prefArray.push_back(prefArray.back() + nums[i]);
        }
        int winStart = 0;
        int winEnd = 0;
        int best = nums.size() + 1;
        if (std::accumulate(nums.begin(), nums.end(), 0) < target){
            return 0;
        }
        while (winEnd < nums.size() + 1){
            int currWindowSum = prefArray[winEnd] - prefArray[winStart];
            if (currWindowSum < target){
                winEnd++;
            } else {
                
                best = min(best, winEnd - winStart);
                winStart++;
            }
        }
        return best;
    }
};