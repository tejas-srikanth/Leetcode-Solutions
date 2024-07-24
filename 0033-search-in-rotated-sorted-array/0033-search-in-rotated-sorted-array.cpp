class Solution {
public:
    int minIndex(vector<int>& nums){
        if (nums.size() == 1){
            return 0;
        }
        int start = 1;
        int end = nums.size() - 1;
        int lst = nums[end];
        if (nums[0] < lst){
            return 0;
        }
        while (start < end){
            int mid = (start + end) / 2;
            if (nums[mid] <= nums[end]){
                if (nums[mid-1] > nums[end]){
                    return mid;
                } else {
                    end = mid-1;
                }
            } else {
                start = mid+1;
            }
        }
        return start;
    }
    int search(vector<int>& nums, int target) {
        int minind = minIndex(nums);
        int start = 0;
        int end = nums.size() - 1;
        int n = nums.size();
        while (start <= end){
            int mid = (start + end) / 2;
            if (nums[(mid + minind) % n] > target){
                end = mid-1;
            }

            else if (nums[(mid + minind) % n] < target){
                start = mid+1;
            }

            else {
                return (mid + minind) % n;
            }
        }
        return -1;
    }
};