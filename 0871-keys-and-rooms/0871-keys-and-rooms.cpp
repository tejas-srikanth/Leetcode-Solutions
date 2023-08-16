class Solution {
public:

    void dfs(unordered_map<int, vector<int>>& g, vector<bool>& v, int start){
        v[start] = true;
        for (int c: g[start]){
            if (!v[c]){
                dfs(g, v, c);
            }
        }
    }


    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        unordered_map<int, vector<int>> fg;
        unordered_map<int, vector<int>> bg;
        vector<bool> fv(rooms.size(), false);
        vector<bool> bv(rooms.size(), false);

        for (int i=0; i<rooms.size(); ++i){
            fg[i] = rooms[i];
            for (int k: rooms[i]){
                if (bg.find(k) != bg.end()){
                bg[k].push_back(i);
                } else {
                    bg[k] = {i};
                }
            }
        }
        for (bool c: fv){ cout << c << " "; }
        dfs(fg, fv, 0);
    
        
        dfs(bg, bv, 0);
        for (int i=0; i<fv.size(); ++i){
            if (!fv[i] && !bv[i]){
                return false;
            } 
        }
        return true;
    }
};