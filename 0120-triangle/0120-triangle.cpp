class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        vector<int> dp(triangle.size(), 0);
        for (int i=0; i<triangle.size(); ++i){
            if (i == 0){
                dp[0] = triangle[0][0];
            } else {
                int repl = -1;
                int tmp;
                for (int j=0; j<triangle[i].size(); j++){
                    int k = dp[j];
                    if (j == 0){
                        repl = k;
                        dp[j] = dp[j] + triangle[i][j];
                    } else if (j == triangle[i].size() - 1) {
                        cout << repl << endl;
                        dp[j] = repl + triangle[i][j];
                    } else {
                        tmp = dp[j];
                        dp[j] = min(dp[j], repl)+triangle[i][j];
                        repl = tmp;
                    }
                }
            }
            for (int j: dp){ cout << j << " "; }
            cout << endl;
        }
        return *min_element(dp.begin(), dp.end());
    }
};