class Solution {
public:
    int majorityElement(vector<int>& nums) {
        map<int, int> m;
        for (int c: nums){
            if (m.find(c) == m.end()){
                m[c] = 1;
            } else {
                m[c]++;
            }
        }
        for (pair<int, int> p: m){
            if (p.second > (nums.size() / 2)){
                return p.first;
            }
        }
        return -1;
    }
};