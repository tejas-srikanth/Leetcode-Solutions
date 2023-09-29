typedef unsigned long long ull;
class Solution {
public:
    int uniquePaths(int m, int n) {
        ull x[100][100];
        for (int i=0; i<m; ++i){
            for (int j=0; j<n; ++j){
                if (i != 0){
                    if (j != 0){
                        x[i][j] = x[i-1][j] + x[i][j - 1];
                    } else{
                        x[i][j] = x[i-1][j];
                    }
                } else{
                    if (j != 0){
                        x[i][j] = x[i][j - 1];
                    } else{
                        x[i][j] = 1;
                    }
                }
            }
        }
        return x[m - 1][n - 1];
    }
};