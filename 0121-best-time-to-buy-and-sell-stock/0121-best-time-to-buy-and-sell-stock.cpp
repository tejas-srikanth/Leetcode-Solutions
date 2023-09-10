class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int currMaxPrice = -1;
        int currMaxProf = -1;
        for (int i=prices.size() - 1; i >= 0; --i){
            if (prices[i] > currMaxPrice){
                currMaxPrice = prices[i];
            }
            if (currMaxPrice - prices[i] > currMaxProf){
                currMaxProf = currMaxPrice - prices[i];
            }
        }
        return currMaxProf;
    }
};