class Solution {
public:
    vector<vector<int>> subsetsHelper(vector<int>& nums, int ind){
        if (ind == nums.size()){

            vector<vector<int>> res = {};
            res.push_back({});
            return res;
        } else {
            vector<vector<int>> res;
            vector<vector<int>> otherSubsets = subsetsHelper(nums, ind+1);
            for (vector<int> sub: otherSubsets){
                res.push_back(sub);
                sub.push_back(nums[ind]);
                res.push_back(sub);
            }
            return res;
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        return subsetsHelper(nums, 0);
    }
};