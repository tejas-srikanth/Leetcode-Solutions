class Solution {
public:
    int digSum(int num){
        int s = 0;
        while (num > 0){
            s += (num % 10);
            num = num / 10;
        }
        return s;
    }

    int twoLargestSum(vector<int>& nums){
        int currFirstMax = max(nums[0], nums[1]);
        int currSecondMax = min(nums[0], nums[1]);
        for (int i=2; i<nums.size(); ++i){
            if (nums[i] > currFirstMax){
                currSecondMax = currFirstMax;
                currFirstMax = nums[i];
            } else if (nums[i] > currSecondMax){
                currSecondMax = nums[i];
            }
        }
        return currFirstMax + currSecondMax;
    }

    int maximumSum(vector<int>& nums) {
        vector<vector<int>> digSums(82);
        for (int num: nums){
            digSums[digSum(num)].push_back(num);
        }
        int currMaxSum = -1;
        for (vector<int> s: digSums){
            if (s.size() > 1){
                currMaxSum = max(currMaxSum, twoLargestSum(s));
            }
        }
        return currMaxSum;
    }
};