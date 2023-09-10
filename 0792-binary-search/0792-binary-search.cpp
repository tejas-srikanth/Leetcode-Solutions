class Solution {
public:
    int search(vector<int>& nums, int target) {
        int st = 0;
        int end = nums.size() - 1;
        int mid = (st + end) / 2;
        while (st <= end){
            
            if (nums[mid] > target){
                end = mid - 1;
            } else if (nums[mid] < target){
                st = mid + 1;
            } else {
                return mid;
            }
            mid = (st + end) / 2;
        }
        return -1;
    }
};