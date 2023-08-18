class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        int numVars = 0;
        unordered_map<string, int> m;
        for (vector<string> s: equations){
            if (m.find(s[0]) == m.end()){
                m[s[0]] = numVars;
                numVars++;
            }
            if (m.find(s[1]) == m.end()){
                m[s[1]] = numVars;
                numVars++;
            }
            
        }
        vector<vector<double>> g;
        vector<double> x(numVars, 0);
        for (int i=0; i<numVars; ++i){
            g.push_back(x);
        }
        int i = 0;
        for (vector<string> eq: equations){
            g[m[eq[0]]][m[eq[1]]] = values[i];
            g[m[eq[1]]][m[eq[0]]] = 1/values[i];
            ++i;
        }
        for (int i=0; i<numVars; ++i){
            g[i][i] = 1;
        }
        vector<double> t;
        vector<bool> v(numVars, false);

        for (vector<string> r: queries){
            queue<pair<int, double>> q;
            vector<bool> v(numVars, false);
            if (m.find(r[0]) == m.end() || m.find(r[1]) == m.end()){
                t.push_back(-1);
            } else {
                int a = m[r[0]];
                int b = m[r[1]];
                q.push({a, 1.0});
                bool br = false;
                if (a == b){
                    t.push_back(1);
                    continue;
                }
                while (!q.empty()){
                    pair<int, double> p = q.front();
                    q.pop();
                    v[p.first] = true;
                    cout << p.first << " ";
                    for (int i=0; i<numVars; ++i){
                        if (g[p.first][i]!=0 && !v[i]){
                            if (i == b){
                                t.push_back(g[p.first][i] * p.second);
                                br = true;
                                break;
                            } else {
                                q.push({i, g[p.first][i] * p.second});
                            }
                        }
                    }
                    if (br){
                        break;
                    }
                }
                if (!br){
                    t.push_back(-1);
                }
            }
        }
          
        return t;
    }
};