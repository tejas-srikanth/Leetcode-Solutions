class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount+1, 10020);
        dp[0] = 0;
        for (int i=1; i<amount+1; ++i){
            bool canMakeChange = false;
            for (int coin: coins){
                if (i - coin >= 0){
                    if (dp[i - coin] != -1){
                        dp[i] = min(dp[i], dp[i - coin] + 1);
                        canMakeChange = true;
                    }
                } 
            }
            if (!canMakeChange){
                dp[i] = -1;
            }
        }
        return dp[amount];
    }
};