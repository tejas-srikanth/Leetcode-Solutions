class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for (int i=0; i<9; ++i){
            int row[10] = {0};
            int col[10] = {0};
            for (int j=0; j<9; ++j){
                if (board[i][j] != '.'){
                    row[board[i][j] - '0']++;
                    if (row[board[i][j] - '0'] > 1) return false;
                }

                if (board[j][i] != '.'){
                    cout << board[j][i] - '0' << endl;
                    col[board[j][i] - '0']++;
                    if (col[board[j][i] - '0'] > 1) return false;
                }
            }
        }
        for (int i=0; i<3; i++){
            for (int j=0; j<3; j++){
                int square[10] = {0};
                for (int squarei=0; squarei<3; squarei++){
                    for (int squarej=0; squarej<3; squarej++){
                        if (board[3 * i + squarei][3 * j + squarej]!= '.'){ 
                        square[board[3 * i + squarei][3 * j + squarej] - '0']++;
                        if (square[board[3 * i + squarei][3 * j + squarej] - '0'] > 1) return false;
                        }
                    }
                }
            }
        }
        return true;
    }
};