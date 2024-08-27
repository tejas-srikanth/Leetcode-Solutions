class Solution {
public:
    vector<vector<int>> helper(vector<int>& unique, vector<int>& occ, int target, int ind){
        vector<vector<int>> res;
        if (target < 0){
            return {};
        } else if (target == 0){
            return {{}};
        }
        if (ind == unique.size()){
            return res;
        }
        int k = occ[ind];
        for (int i=0; i<=k; ++i){
            vector<vector<int>> helperRes = helper(unique, occ, target - i * unique[ind], ind+1);
            for (vector<int> x: helperRes){
                for (int j=0; j < i; j++){
                    x.push_back(unique[ind]);
                }
                res.push_back(x);
            }
            occ[ind]--;
        }
        occ[ind] = k;
        
        return res;
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<int> unique;
        vector<int> occ;
        for (int i=0; i<candidates.size(); ++i){
            if (i == 0 || candidates[i] != candidates[i-1]){
                unique.push_back(candidates[i]);
                occ.push_back(1);
            } else {
                occ[occ.size() - 1]++;
            }
        }
        return helper(unique, occ, target, 0);
    }
};