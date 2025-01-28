class Solution {
public:
    vector<vector<int>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    int dfs(vector<vector<bool>>& visited, vector<vector<int>>& grid, int i, int j, int m, int n){
        visited[i][j] = true;
        int k = grid[i][j];
        for (vector<int> dir: dirs){
            int in = i + dir[0], jn = j + dir[1];
            if (in >= 0 && in < m && jn >= 0 && jn < n && !visited[in][jn] && grid[in][jn]){
                k += dfs(visited, grid, in, jn, m, n);
            }
        }
        return k;
    }

    int findMaxFish(vector<vector<int>>& grid) {
        vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size(), false));
        int m = grid.size(), n = grid[0].size();
        int maxGridScore = 0;
        for (int i=0; i<m; ++i){
            for (int j=0; j<n; ++j){
                if (!visited[i][j] && grid[i][j]){
                    maxGridScore = max(maxGridScore, dfs(visited, grid, i, j, m, n));
                }
            }
        }
        return maxGridScore;
    }
};