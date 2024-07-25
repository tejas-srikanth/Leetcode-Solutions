class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int currMin = prices[0];
        int currMax = -1;
        for (int price: prices){
            currMax = max(currMax, price - currMin);
            currMin = min(price, currMin);
        }
        return currMax;
    }
};