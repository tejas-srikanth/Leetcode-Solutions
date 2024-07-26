class Solution {
public:

    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq;
        vector<int> res;
        int winStart = 0;
        for (int i=0; i<nums.size(); ++i){
            if (i < k){
                if (dq.empty()){
                    dq.push_back(nums[i]);
                } else  {
                    while (!dq.empty() && dq.front() < nums[i]){
                        dq.pop_front();
                    }
                    dq.push_front(nums[i]);
                }
            } else {
                res.push_back(dq.back());
                if (dq.back() == nums[winStart]){
                    dq.pop_back();
                }
                while (!dq.empty() && dq.front() < nums[i]){
                        dq.pop_front();
                    }
                dq.push_front(nums[i]);
                winStart++;
            }  
        }
        res.push_back(dq.back());
        return res;
    }
};