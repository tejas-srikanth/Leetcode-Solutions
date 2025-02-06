class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        unordered_map<int, int> um;
        int numTuples = 0;
        for (int i=0; i<nums.size(); ++i){
            for (int j=i+1; j<nums.size(); ++j){
                if (um.find(nums[i] * nums[j]) == um.end()){
                    um[nums[i] * nums[j]] = 0;
                }
                numTuples += 2 * um[nums[i] * nums[j]];
                um[nums[i] * nums[j]] += 2;
            }
        }
        return numTuples * 2;
    }
};