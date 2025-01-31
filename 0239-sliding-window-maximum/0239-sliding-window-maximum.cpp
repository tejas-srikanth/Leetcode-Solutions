class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        set<pair<int, int>> currWindow;
        for (int i=0; i<k; ++i){
            currWindow.insert({nums[i], i});
        }
        vector<int> res;
        for (int i=k; i<nums.size(); ++i){
            res.push_back(prev(currWindow.end())->first);
            currWindow.erase(currWindow.find({nums[i-k], i-k}));
            currWindow.insert({nums[i], i});
        }
        res.push_back(prev(currWindow.end())->first);
        return res;
    }
};