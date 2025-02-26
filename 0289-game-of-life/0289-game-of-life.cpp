class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        vector<vector<int>> dirs = {{0, -1}, {1, 0}, {-1, 0}, {0, 1}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};
        int m = board.size(), n = board[0].size();
        for (int i=0; i<m; i++){
            for (int j=0; j<n; j++){
                int liveCount = 0;
                for (vector<int> dir: dirs){
                    int newJ = j + dir[1];
                    int newI = i + dir[0];
                    if (newJ >= 0 && newJ < n && newI >= 0 && newI < m){
                        liveCount += (board[newI][newJ] > 0);
                    }
                }
                
                if (board[i][j]){
                    if (liveCount < 2 || liveCount > 3){
                        board[i][j] = 2;
                    }
                }
                if (!board[i][j]){
                    if (liveCount == 3){
                        board[i][j] = -1;
                    }
                }
            }
        }
        
        for (int i=0; i<m; i++){
            for (int j=0; j<n; j++){
                if (board[i][j] == 2){
                    board[i][j] = 0;
                } else if (board[i][j] == -1){
                    board[i][j] = 1;
                }
            }
        }
        
        
    }
};