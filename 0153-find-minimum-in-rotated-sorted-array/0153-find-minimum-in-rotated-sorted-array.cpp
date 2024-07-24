class Solution {
public:
    int findMin(vector<int>& nums) {
        int start = 1;
        int end = nums.size() - 1;
        int lst = nums[end];
        if (nums.size() == 1){
            return nums[0];
        }
        if (nums[0] < nums[end]){
            return nums[0];
        }
        while (start <= end){
            int mid = (start + end) / 2;
            
            if (nums[mid] >= lst){
                if (nums[mid-1] > nums[mid]){
                    cout << start << " " << end << " " << mid << endl;
                    return nums[mid];
                } else {
                    start = mid + 1;
                    
                }
            } else {
                end = mid - 1;
            }
        }
        return nums[start];
    }
};