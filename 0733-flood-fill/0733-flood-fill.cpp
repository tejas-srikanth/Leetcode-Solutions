class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        queue<pair<int, int>> q;
        vector<vector<bool>> v;
        for (int i=0; i<image.size(); ++i){
            vector<bool> x(image[0].size(), false);
            v.push_back(x);
        }
        q.push({sr, sc});
        int oColor = image[sr][sc];
        while (!q.empty()){
            pair<int, int> p = q.front();
            q.pop();
            if (0 <= p.first && p.first <= image.size() - 1 && 0 <= p.second && p.second <= image[0].size() - 1 && !v[p.first][p.second]){
                
                v[p.first][p.second] = true;
                if (image[p.first][p.second] == oColor){
                    q.push({p.first - 1, p.second});
                    q.push({p.first, p.second - 1});
                    q.push({p.first + 1, p.second});
                    q.push({p.first, p.second + 1});
                    image[p.first][p.second] = color;
                }
            }
        }
        return image;
    }
};