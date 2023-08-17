class Solution {
public:
    void dfs(vector<vector<int>>& isConnected, unordered_set<int>& s, int start){
        for (int i=0; i<isConnected.size(); ++i){
            s.erase(start);
            if ((isConnected[start][i]) && (s.find(i) != s.end())){
                
                dfs(isConnected, s, i);
                
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int numProvinces = 0;
        unordered_set<int> s;
        for (int i=0; i<isConnected.size(); ++i){
            s.insert(i);
        }
        while (!s.empty()){
            cout << *s.begin() << endl;
            dfs(isConnected, s, *s.begin());
            numProvinces++;
        }
        return numProvinces;
    }
};