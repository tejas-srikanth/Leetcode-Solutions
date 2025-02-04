class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int k = -1;
        for (int i=nums.size()-2; i >= 0; --i){
            if (nums[i] < nums[i+1]){
                k = i;
                break;
            }
        }
        if (k == -1){
            std::reverse(nums.begin(), nums.end());
            return;
        }
        std::reverse(nums.begin()+k+1, nums.end());
        auto it = std::upper_bound(nums.begin()+k+1, nums.end(), nums[k]);
        std::swap(nums[k], *it);

        

    }
};