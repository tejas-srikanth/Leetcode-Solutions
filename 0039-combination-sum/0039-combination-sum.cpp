class Solution {
public:
    vector<vector<int>> combinationSumHelper(vector<int>& candidates, int target, int ind) {
        vector<vector<int>> res;
        if (target == 0){
            return {{}};
        } else if (target < 0){
            return {};
        }
        for (int i=ind; i < candidates.size(); ++i){
            int candidate = candidates[i];
            vector<vector<int>> comboSum = combinationSumHelper(candidates, target - candidate, i);
            for (vector<int> cs: comboSum){
                cs.push_back(candidate);
                res.push_back(cs);
            }
        }
        return res;
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target){
        return combinationSumHelper(candidates, target, 0);
    }
};