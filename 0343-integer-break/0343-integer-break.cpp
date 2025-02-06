class Solution {
public:
    int integerBreak(int n) {
        vector<int> dp(n+1, 0);
        dp[0] = 1;
        dp[1] = 1;
        for (int i=2; i<n+1; ++i){
            int currMax = -1;
            for (int j=0; j<i; ++j){
                currMax = max({currMax, dp[j] * (i - j), (j + 1) * (i - j)});
            }
            dp[i] = currMax;
        }
        return dp[n-1];
    }
};