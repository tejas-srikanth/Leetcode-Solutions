class Solution {
public:

    void solve(vector<vector<vector<bool>>>& dp, string s1, string s2, string s3){
        int s1len = s1.length();
        int s2len = s2.length();
        int s3len = s3.length();
        for (int i=0; i<=s1len; ++i){
            for (int j=0; j<=s2len; ++j){
                for (int k=0; k<=s3len; ++k){
                    if (k == 0){
                        if (i == 0 && j == 0){
                            dp[i][j][k] = 1;
                        } else {
                            dp[i][j][k] = 0;
                        }
                    } else if (i == 0){
                        if (j == 0){
                            dp[i][j][k] = 0;
                        } else {
                            dp[i][j][k] = (dp[i][j-1][k-1] && s2[j-1] == s3[k-1]);
                        }
                    } else if (j == 0){
                        dp[i][j][k] = (dp[i-1][j][k-1] && s1[i-1] == s3[k-1]);
                    } else {
                        if (s1[i-1] == s3[k-1]){
                            if (s2[j-1] == s3[k-1]){
                                dp[i][j][k] = (dp[i-1][j][k-1] || dp[i][j-1][k-1]);
                            } else {
                                dp[i][j][k] = dp[i-1][j][k-1];
                            }
                        } else if (s2[j-1] == s3[k-1]) {
                            dp[i][j][k] = dp[i][j-1][k-1];
                        } else {
                            dp[i][j][k] = 0;
                        }
                    }
                }
            }
        }

    }
    bool isInterleave(string s1, string s2, string s3) {
        vector<vector<vector<bool>>> dp;
        for (int i=0; i<=s1.length(); ++i){
            vector<vector<bool>> m;
            for (int j=0; j<=s2.length(); ++j){
                vector<bool> x;
                for (int k=0; k<=s3.length(); ++k){
                    x.push_back(false);
                }
                m.push_back(x);
            }
            dp.push_back(m);
        }
        solve(dp, s1, s2, s3);
        return dp[s1.length()][s2.length()][s3.length()];
    }
};