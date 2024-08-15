class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size() - 1;
        vector<int> nCount(n+1, 0);
        int start = 0;
        int ptr = 0;
        nCount[start] += 1;
        while (ptr < n+1){
            ptr = nums[ptr] - 1;
            if (nCount[ptr] > 0){
                if (start == ptr){
                    while (nCount[ptr]){
                        ptr++;
                    }
                    start = ptr;
                    nCount[ptr] += 1;
                } else {
                    return ptr + 1;
                }
            } else {
                nCount[ptr]++;
            }

        }
        return -1;
    }
};