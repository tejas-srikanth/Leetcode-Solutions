class Solution {
public:
    int getIndex(char c){
        if (c - 'a' >= 0){
            return c - 'a';
        } else {
            return 26 + c - 'A';
        }
    }
    int findMin(vector<queue<int>> vq, int n){
        int currMin = n + 1;
        for (queue<int> q: vq){
            if (!q.empty() && q.front() < currMin){
                currMin = q.front();
            }
        }
        return currMin;
    }

    string minWindow(string t, string s) {
        vector<int> sL(52, -1);
        for (char c: s){
            if (sL[getIndex(c)] == -1){
                sL[getIndex(c)] = 1;
                
            } else {
                sL[getIndex(c)] += 1;
            }
        }
        int m = s.length();
        vector<queue<int>> vq(52);
        int n = t.length();
        int minIndex = n-1;
        pair<int, int> bestIndex = {-1, n+1};
        
        for (int i=0; i<n; ++i){
            char c = t[i];
            int x = getIndex(c);
            if (sL[x] > 0){
                sL[x]--;
                m--;
                vq[x].push(i);
                if (m == 0){
                    int j = findMin(vq, n);
                    minIndex = j;
                    if (i - j < bestIndex.second - bestIndex.first){
                        bestIndex.second = i;
                        bestIndex.first = j;
                    }
                }
            } else if (sL[x] == 0){
                int a = vq[x].front();
                vq[x].pop();
                vq[x].push(i);
                if (m == 0){
                    if (a == minIndex){
                        int j = findMin(vq, n);
                        minIndex = j;
                        if (i - j < bestIndex.second - bestIndex.first){
                            bestIndex.second = i;
                            bestIndex.first = j;
                        }
                    }
                }
            } 
        }
        if (m != 0){
            return "";
        }
        return t.substr(bestIndex.first, bestIndex.second - bestIndex.first + 1);
    }
};