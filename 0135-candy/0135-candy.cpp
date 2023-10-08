class Solution {
public:
    int candy(vector<int>& ratings) {
        vector<int> c;
        int n = ratings.size();
        c.push_back(1);
        for (int i=1; i<n; ++i){
            if (ratings[i] > ratings[i - 1]){
                c.push_back(c.back() + 1);
            } else {
                c.push_back(1);
            }
        }
        for (int i: c){ cout << i << " "; }
        cout << endl;
        int curr = 1;
        for (int i=n - 1; i >= 0; --i){
            if (i == n - 1){
                c[i] = max(curr, c[i]);
            } else {
                if (ratings[i] > ratings[i + 1]){
                    curr += 1;
                } else {
                    curr = 1;
                }
                c[i] = max(curr, c[i]);
            }

        }
        int s = 0;
        for (int k: c){ s += k; }
        return s;
    }
};