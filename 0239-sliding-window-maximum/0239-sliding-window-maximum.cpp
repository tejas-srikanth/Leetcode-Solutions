class Solution {
public:
    deque<int> pd(deque<int>& dq){
        deque<int> odq;
        while (!dq.empty()){
            odq.push_back(dq.front());
            cout << dq.front() << " ";
            dq.pop_front();
        }
        cout << endl;
        return odq;
    }
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
                if (dq.back() == 0){
                    cout << dq.size() << endl;
                    cout << dq.front() << endl;
                }
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