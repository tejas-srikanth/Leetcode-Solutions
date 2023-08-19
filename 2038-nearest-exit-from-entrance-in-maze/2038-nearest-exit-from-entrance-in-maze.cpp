class Solution {
public:
    bool isEdge(pair<int, int> x, int w, int l){
        int a = x.first;
        int b = x.second;
        return (a == 0 || b == 0 || a == w-1 || b == l-1);
    }
    bool isInBounds(pair<int, int> x, int w, int l){
        int a = x.first;
        int b = x.second;
        return (a >= 0 && b >= 0 && a <= w-1 && b <= l-1);
    }
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int w = maze.size();
        int l = maze[0].size();

        vector<vector<bool>> v(w, vector<bool>(l, false));
        queue<pair<int, int>> q;
        vector<pair<int, int>> dvecs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    
        q.push({entrance[0], entrance[1]});
        v[entrance[0]][entrance[1]] = true;
        int p = 0;
        while (!q.empty()){
            int s = q.size();
            for (int i=0; i<s; ++i){
                pair<int, int> x = q.front();
                cout << x.first << " " << x.second << endl;
                q.pop();
                if (p && isEdge(x, w, l)){
                    return p;
                } else {
                    for (pair<int, int> dv: dvecs){
                        int newX = dv.first + x.first;
                        int newY = dv.second + x.second;
                        pair<int, int> newP = {newX, newY};
                        
                        if (isInBounds(newP, w, l) && !v[newX][newY] && maze[newX][newY] == '.'){
                            cout << "newP: " << newP.first << " " << newP.second << endl;
                            v[newP.first][newP.second] = true;
                            q.push(newP);
                        }
                    }
                }
                
            }
            p++;
        }
        return -1;
    }
};