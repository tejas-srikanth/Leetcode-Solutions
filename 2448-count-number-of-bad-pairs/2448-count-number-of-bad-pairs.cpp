class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        unordered_map<int, int> lineMap;
        long long badPairs = 0;
        for (int i=0; i<nums.size(); ++i){
            int xint = i - nums[i];
            if (lineMap.find(xint) == lineMap.end()){
                badPairs += i;
                lineMap[xint] = 0;
            } else {
                badPairs += i - lineMap[xint];
            }
            lineMap[xint]++;
        }
        return badPairs;
    }
};