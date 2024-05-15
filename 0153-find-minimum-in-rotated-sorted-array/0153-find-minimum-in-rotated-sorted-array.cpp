class Solution {
public:
    int findMin(vector<int>& nums) {
        int beg = 0;
        int end = nums.size() - 1;
        int mid = beg + (end - beg) / 2;
        int firstNum = nums[0];
        while (beg < end){
            mid = beg + (end - beg) / 2;
            if (nums[mid] < firstNum){
                end = mid - 1;
            } else {
                if (nums[mid+1] < nums[mid]){
                    return nums[mid+1];
                } else {
                    beg = mid+1;
                }
            }
        }
        if ((end == beg) && (beg== nums.size() - 1)){
            return firstNum;
        } else {
            return nums[end+1];
        }
    }
};