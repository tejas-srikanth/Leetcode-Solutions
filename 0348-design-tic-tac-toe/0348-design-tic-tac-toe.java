class TicTacToe {
    int rowScores[];
    int colScores[];
    int diagScore = 0;
    int offDiagScore = 0;
    int n;

    public TicTacToe(int N) {
        rowScores = new int[N];
        colScores = new int[N];
        n = N;
    }
    
    public int move(int row, int col, int player) {
        int adder = -1;
        if (player == 2){
            adder = 1;
        }

        rowScores[row] += adder;
        if (rowScores[row] == adder * n){
            return player;
        }

        colScores[col] += adder;
        if (colScores[col] == adder * n){
            return player;
        }

        if (row == col){
            diagScore += adder;
            if (diagScore == adder * n){
                return player;
            }
        }

        if (n - row - 1 == col){
            offDiagScore += adder;
            if (offDiagScore == adder * n){
                return player;
            }
        }
        return 0;
    }
}

/**
 * Your TicTacToe object will be instantiated and called as such:
 * TicTacToe obj = new TicTacToe(n);
 * int param_1 = obj.move(row,col,player);
 */