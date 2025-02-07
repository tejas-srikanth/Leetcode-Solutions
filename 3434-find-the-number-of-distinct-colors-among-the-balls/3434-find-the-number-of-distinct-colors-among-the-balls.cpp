class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        map<int, int> ballColor;
        map<int, int> colFreq;
        vector<int> res;
        for (vector<int> query: queries){
            if (ballColor.find(query[0]) == ballColor.end()){
                ballColor[query[0]] = query[1];
                if (colFreq.find(query[1]) == colFreq.end()){
                    colFreq[query[1]] = 0;
                }
                colFreq[query[1]]++;
            } else {
                colFreq[ballColor[query[0]]]--;
                if (colFreq[ballColor[query[0]]] == 0){
                    colFreq.erase(colFreq.find(ballColor[query[0]]));
                }
                if (colFreq.find(query[1]) == colFreq.end()){
                    colFreq[query[1]] = 0;
                }
                colFreq[query[1]]++;
                ballColor[query[0]] = query[1];
            }
            res.push_back(colFreq.size());
        }
        return res;
    }
};