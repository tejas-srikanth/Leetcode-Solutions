class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        if (s1.length() + s2.length() != s3.length()){
            return false;
        }
        vector<vector<bool>> dp(s1.size() + 1, vector<bool>(s2.size() + 1));
        for (int i=0; i<=s2.size(); ++i){
            if (i == 0){
                dp[0][0] = true;
            } else {
                dp[0][i] = (dp[0][i-1] && s2[i-1] == s3[i-1]);
            }
        }
        for (int j=1; j<=s1.size(); ++j){
            dp[j][0] = (dp[j-1][0] && s1[j-1] == s3[j-1]);
        }
        for (int i=1; i<=s1.size(); ++i){
            for (int j=1; j<=s2.size(); ++j){
                int s3Ind = i + j - 1;
                dp[i][j] = ((dp[i][j-1] && s3[s3Ind] == s2[j-1]) || (dp[i-1][j] && s3[s3Ind] == s1[i-1])); 
            }
        }
        return dp.back().back();
    }
};