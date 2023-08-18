class Solution {
public:
    void dfs(unordered_map<int, vector<pair<int, bool>>>& fg, vector<int>& change, int start){
        for (pair<int, bool> c: fg[start]){
            if (!change[c.first]){
                if (!c.second){
                    change[c.first] = 1;
                } else {
                    change[c.first] = -1;
                }
                dfs(fg, change, c.first);
            }
        }

    }
    int minReorder(int n, vector<vector<int>>& connections) {
        unordered_map<int, vector<pair<int, bool>>> fg;
        vector<int> change(n, 0);
        for (vector<int> x: connections){
            fg[x[0]].push_back({x[1], false});
            fg[x[1]].push_back({x[0], true});
        }
        change[0] = -1;
        dfs(fg, change, 0);
        int tot = 0;
        for (int c: change){
            if (c == 1){
                tot++;
            }
        }
        return tot;
    }
};