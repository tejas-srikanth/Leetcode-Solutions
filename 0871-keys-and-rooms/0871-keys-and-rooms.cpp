class Solution {
public:

    void dfs(vector<vector<int>>& rooms, vector<bool>& v, int start){
        v[start] = true;
        for (int c: rooms[start]){
            if (!v[c]){
                dfs(rooms, v, c);
            }
        }
    }


    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        vector<bool> fv(rooms.size(), false);
        dfs(rooms, fv, 0);
    
        for (int i=0; i<fv.size(); ++i){
            if (!fv[i]){
                return false;
            } 
        }
        return true;
    }
};