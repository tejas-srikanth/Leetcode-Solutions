class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int nZ = !nums[0], nO = nums[0];
        int start = 0, end = 1;
        int currMax = 0;
        while (end < nums.size()){
            if (nZ <= k){
                nZ += !nums[end];
                nO += nums[end];
                end++;
                currMax = max(end - start - 1, currMax);
            } else {
                nZ += !nums[end];
                nO += nums[end];
                nZ -= !nums[start];
                nO -= nums[start];
                end++;
                start++;
            }
        }
        if (nZ <= k){
            currMax = max(end - start, currMax);
        }
        return currMax;
    }
};