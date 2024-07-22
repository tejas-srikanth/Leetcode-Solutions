class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> dt(101);
        vector<int> others(temperatures.size(), 0);
        for (int i=temperatures.size() - 1; i >= 0; i--){
            if (i == temperatures.size() - 1){
                dt[temperatures[i]] = temperatures.size() - 1;
                continue;
            }
            int currMin = 1e6;
            for (int j=temperatures[i] + 1; j <= 100; ++j){

                if (dt[j] != 0){

                    currMin = min(currMin, dt[j] - i);
                }
            }

            if (currMin == 1e6){
                others[i] = 0;
            } else {
                others[i] = currMin;
            }
            dt[temperatures[i]] = i;
        }
        return others;
    }
};