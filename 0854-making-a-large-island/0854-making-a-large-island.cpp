class Solution {
public:
    vector<vector<int>> dirs = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
    int dfs(vector<vector<int>>& grid, int id, int i, int j){
        grid[i][j] = id;
        int totalSize = 1;
        for (vector<int> dr: dirs){
            int newI = i + dr[0], newJ = j + dr[1];
            if (newI >= 0 && newJ >= 0 && newI < grid.size() && newJ < grid[0].size() && grid[newI][newJ] == 1){
                totalSize += dfs(grid, id, newI, newJ);
            }
        }
        return totalSize;
    }
    int largestIsland(vector<vector<int>>& grid) {
        int id = 2;
        unordered_map<int, int> islandSizes;
        int maxIslandSize = 0;
        for (int i=0; i<grid.size(); ++i){
            for (int j=0; j<grid[0].size(); ++j){
                if (grid[i][j] == 1){
                    int islandSize = dfs(grid, id, i, j);
                    maxIslandSize = max(islandSize, maxIslandSize);
                    islandSizes[id] = islandSize;
                    id++;
                }
            }
        }
        // for (vector<int> k: grid){ for (int j: k){ std::cout << j << " "; }; std::cout << std::endl;}
        int currMax = 0;
        for (int i=0; i<grid.size(); ++i){
            for (int j=0; j<grid[0].size(); ++j){
                if (grid[i][j] == 0){
                    vector<int> vals;
                    set<int> usedIslands;
                    for (vector<int> dir: dirs){
                        int newI = i + dir[0], newJ = j + dir[1];
                        if (newI >= 0 && newJ >= 0 && newI < grid.size() && newJ < grid[0].size() && grid[newI][newJ] != 0 && usedIslands.find(grid[newI][newJ]) == usedIslands.end()){
                            
                            vals.push_back(islandSizes[grid[newI][newJ]]);
                            usedIslands.insert(grid[newI][newJ]);
                        } else {
                            vals.push_back(0);
                        }
                    }
                    int currSum = 0;
                    for (int i: vals){
                        if (i > 0){
                            currSum += i;
                        }
                    }
                    currMax = max(currMax, currSum + 1);
                }
            }
        }
        return max(currMax, maxIslandSize);
    }
};