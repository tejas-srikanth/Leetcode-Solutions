class Solution {
public:
    vector<vector<int>> helper(vector<int>& unique, vector<int>& occurrences, int ind){
        if (ind == unique.size()){
            return {{}};
        } else {
            vector<vector<int>> nextCall = helper(unique, occurrences, ind+1);
            vector<vector<int>> res;
            for (vector<int> c: nextCall){
                res.push_back(c);
                for (int i=0; i<occurrences[ind]; ++i){
                    c.push_back(unique[ind]);
                    res.push_back(c);
                }
            }
            return res;
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> unique;
        vector<int> occurrences;
        for (int i=0; i<nums.size(); ++i){
            if (unique.size() == 0 || nums[i] != nums[i-1]){
                unique.push_back(nums[i]);
                occurrences.push_back(1);
            }
            else {
                int n = occurrences.size() - 1;
                occurrences[n] = occurrences[n] + 1;
            } 
        }
        return helper(unique, occurrences, 0);
    }
};