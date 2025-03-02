
class Solution {
public:
    int minCut(string s) {
        vector<vector<int>> theGraph(s.length() + 1, vector<int>());
        for (int i=0; i<s.length(); ++i){
            int pal_start = i;
            int pal_end = i;
            while (pal_start >= 0 && pal_end < s.length()){
                if (s[pal_end] == s[pal_start]){
                    theGraph[pal_start].push_back(pal_end + 1);
                    pal_start--;
                    pal_end++;
                } else {
                    break;
                }
            }

            pal_start = i;
            pal_end = i + 1;
            while (pal_start >= 0 && pal_end < s.length()){
                if (s[pal_end] == s[pal_start]){
                    theGraph[pal_start].push_back(pal_end + 1);
                    pal_start--;
                    pal_end++;
                } else {
                    break;
                }
            }
        }

        deque<pair<int, int>> q;
        vector<bool> visited(s.length() + 1, false);
        q.push_back({ 0, 0 });
        visited[0] = true;
        while (q.size() != 0){
            pair<int, int> lastPair = q.front();
            q.pop_front();
            if (lastPair.first == s.length()){
                return lastPair.second - 1;
            }

            for (int neighbour: theGraph[lastPair.first]){
                if (!visited[neighbour]){
                    visited[neighbour] = true;
                    q.push_back({ neighbour, lastPair.second + 1 });
                }
            }
        }
        return -1;

    }
};