class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        int numP = 0;
        unordered_map<int, int> us;
        for (int i: nums){
            if (us.find(i) == us.end()){
                us[i] = 1;
            } else {
                us[i]++;
            }
        }
        
        for (pair<int, int> c: us){
            if (us.find(k - c.first) == us.end()){
                continue;
            } else {
                numP += min(us[k - c.first], us[c.first]);
            }
        }

        return numP / 2;
    }
};