class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        bool zeroRow = false;
        bool zeroCol = false;
        for (int i=0; i<matrix.size(); ++i){
            for (int j=0; j<matrix[0].size(); ++j){
                if (matrix[i][j] == 0){
                    if (i == 0){
                        zeroRow = true;
                    }

                    if (j == 0){
                        zeroCol = true;
                    }
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }

        for (int i=1; i<matrix.size(); ++i){
            if (matrix[i][0] == 0){
                for (int j=1; j<matrix[0].size(); ++j){
                    matrix[i][j] = 0;
                }
            }
        }

        for (int j=1; j<matrix[0].size(); ++j){
            if (matrix[0][j] == 0){
                for (int i=1; i<matrix.size(); ++i){
                    matrix[i][j] = 0;
                }
            }
        }

        if (zeroRow){
            for (int j=0; j<matrix[0].size(); ++j){
                matrix[0][j] = 0;
            }
        }

        if (zeroCol){
            for (int j=0; j<matrix.size(); ++j){
                matrix[j][0] = 0;
            }
        }
    }
};