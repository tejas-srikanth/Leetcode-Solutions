class Solution {
public:
    vector<vector<int>> helper(vector<int>& nums){
        if (nums.size() == 0){
            return {{}};
        } else {
            vector<vector<int>> res;
            for (int i=0; i<nums.size(); ++i){
                if (i == 0 || nums[i] != nums[i-1]){
                    int x = nums[i];
                    nums.erase(nums.begin() + i);
                    vector<vector<int>> newres = helper(nums);
                    for (int i=0; i<newres.size(); ++i){
                        newres[i].push_back(x);
                    }
                    nums.insert(nums.begin() + i, x);
                    res.insert(res.end(), newres.begin(), newres.end());
                }
            }
            return res;
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        return helper(nums);
    }
};