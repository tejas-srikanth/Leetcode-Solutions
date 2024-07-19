class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> um;
        for (int num: nums){
            if (um.find(num) != um.end()){
                um[num]++;
            } else {
                um[num] = 1;
            }
        }
        
        vector<pair<int, int>> data = {};
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        for (auto it=um.begin(); it != um.end(); it++){
            if (pq.size() != k){
                pq.push({it->second, it->first});
            } else {
                if (it->second > pq.top().first){
                    pq.pop();
                    pq.push({it->second, it->first});
                }
            }
        }
        vector<int> mostCommon = {};
        while (!pq.empty()){
            mostCommon.push_back(pq.top().second);
            pq.pop();
        }
        return mostCommon;
    }
};