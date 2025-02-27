class Solution {
public:
    int lenLongestFibSubseq(vector<int>& arr) {
        vector<vector<int>> dp(arr.size(), vector<int>(arr.size(), 0));
        unordered_map<int, int> seen;
        seen[arr[0]] = 0;
        for (int i=1; i<dp.size(); ++i){
            for (int j=0; j<dp[0].size(); ++j){
                if (j > i){
                    if (seen.find(arr[j] - arr[i]) != seen.end()){
                        int lastBestEl = seen[arr[j] - arr[i]];
                        if (dp[lastBestEl][i] == 0){
                            dp[i][j] = max(dp[i][j], 3);
                        } else {
                            dp[i][j] = max(dp[i][j], 1 + dp[lastBestEl][i]);
                        }
                    }
                }
            }
            seen[arr[i]] = i;
        }
        int max_elt = 0;
        for (int i=0; i<dp.size(); ++i){
            for (int j=0; j<dp[0].size(); ++j){
                max_elt = max(max_elt, dp[i][j]);
            }
        }
        return max_elt;
    }
};