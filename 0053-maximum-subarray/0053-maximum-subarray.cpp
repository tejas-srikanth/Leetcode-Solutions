class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        vector<int> precomp;
        int rolling = 0;
        if (nums.size() == 1){
            return nums[0];
        }
        for (int x: nums){
            rolling += x;
            precomp.push_back(rolling);
        }
        int mn = precomp[0];
        int mx = mn;
        int g;
        for (int i=1; i<precomp.size(); ++i){
            g = precomp[i];
            if (g < mn){
                if (max(g - mn, g) > mx){
                    mx = max(g - mn, g);
                }
                mn = g;
            } else {
                if (max(g - mn, g) > mx){
                    mx = max(g - mn, g);
                }
            }
        }
        return mx;
    }
};