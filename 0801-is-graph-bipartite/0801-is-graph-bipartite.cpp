class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        vector<int> visited(graph.size(), -1);
        for (int i=0; i<graph.size(); ++i){
            if (visited[i] == -1){
                queue<pair<int, int>> q;
                q.push({i, 0});
                while (q.size()){
                    int a = q.front().first, b = q.front().second;
                    q.pop();
                    visited[a] = b;
                    for (int n: graph[a]){
                        if (visited[n] == -1){
                            q.push({n, 1 - b});
                        } else if (visited[n] == b) {
                            return false;
                        }
                    }
                }
            }
        }
        return true;
    }
};