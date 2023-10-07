class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        for (int i=0; i<obstacleGrid.size(); ++i){
            for (int j=0; j<obstacleGrid[0].size(); ++j){
                if (i == 0 && j == 0){
                    obstacleGrid[i][j] = !obstacleGrid[i][j];
                } else if (i == 0){
                    
                    obstacleGrid[i][j] = !obstacleGrid[i][j] ? obstacleGrid[i][j - 1] : 0;
                } else if (j == 0){
                    
                    obstacleGrid[i][j] = !obstacleGrid[i][j] ? obstacleGrid[i - 1][j] : 0;
                } else {
                    obstacleGrid[i][j] = !obstacleGrid[i][j] ? obstacleGrid[i][j - 1] + obstacleGrid[i - 1][j] : 0;
                }
            }
        }
        return obstacleGrid[obstacleGrid.size() - 1][obstacleGrid[0].size() - 1];
    }
};