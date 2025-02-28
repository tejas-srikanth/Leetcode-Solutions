class Solution {
public:
    string longestCommonSubsequence(string s1, string s2){
        vector<vector<pair<int, char>>> dp(s1.length() + 1, vector<pair<int, char>>(s2.length() + 1, std::make_pair(0, '0')));
        for (int i=1; i<=s1.length(); ++i){
            for (int j=1; j<=s2.length(); ++j){
                if (s1[i-1] == s2[j-1] && max({dp[i-1][j-1].first + 1, dp[i-1][j].first, dp[i][j-1].first}) == dp[i-1][j-1].first + 1){
                    dp[i][j] = { dp[i-1][j-1].first + 1, s1[i-1] };
                } else {
                    dp[i][j] = { max(dp[i-1][j].first, dp[i][j-1].first), '0'};
                }
            }
        }

        int i = s1.size(), j = s2.size();
        string accString = "";
        while (i > 0 && j > 0){
            if (dp[i][j].second != '0'){
                accString += dp[i][j].second;
            }
            if (s1[i-1] == s2[j-1] && max({dp[i-1][j-1].first + 1, dp[i-1][j].first, dp[i][j-1].first}) == dp[i-1][j-1].first + 1){
                i -= 1;
                j -= 1;
            }

            else if (max({dp[i-1][j-1].first + 1, dp[i-1][j].first, dp[i][j-1].first}) == dp[i-1][j].first){
                i -= 1;
            }

            else {
                j -= 1;
            }
        }
        std::reverse(accString.begin(), accString.end());
        return accString;
    }

    string shortestCommonSupersequence(string str1, string str2) {
        string lcs = longestCommonSubsequence(str1, str2) + '0';
        str1 += '0';
        str2 += '0';
        string scs = "";
        int lcsPtr = 0;
        int str1Ptr = 0;
        int str2Ptr = 0;
        cout << lcs << endl;
        while (str1Ptr < str1.length() && str2Ptr < str2.length()){
            while (str1[str1Ptr] != lcs[lcsPtr]){
                scs += str1[str1Ptr];
                str1Ptr++;
            }

            while (str2[str2Ptr] != lcs[lcsPtr]){
                scs += str2[str2Ptr];
                str2Ptr++;
            }

            scs += lcs[lcsPtr];
            str2Ptr++;
            str1Ptr++;
            lcsPtr++;
        }
        scs.pop_back();
        return scs;
    }
};