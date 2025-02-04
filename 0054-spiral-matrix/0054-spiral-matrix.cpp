class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int boundaryU = 0, boundaryL = 0, boundaryD = matrix.size() - 1, boundaryR = matrix[0].size() - 1;
        char currDir = 'R';
        int currI = 0, currJ = 0;
        vector<int> res;
        while (true){
            
            if (currDir == 'R'){
                if (currJ > boundaryR){
                    break;
                }
                while (currJ <= boundaryR){
                    res.push_back(matrix[currI][currJ]);
                    currJ++;
                }
                currDir = 'D';
                boundaryU++;
                currJ--;
                currI++;
            }
            if (currDir == 'D'){
                if (currI > boundaryD){
                    break;
                }
                while (currI <= boundaryD){
                    res.push_back(matrix[currI][currJ]);
                    currI++;
                }
                currDir = 'L';
                boundaryR--;
                currI--;
                currJ--;
            }
            if (currDir == 'L'){
                if (currJ < boundaryL){
                    break;
                }
                while (currJ >= boundaryL){
                    res.push_back(matrix[currI][currJ]);
                    currJ--;
                }
                currDir = 'U';
                boundaryD--;
                currJ++;
                currI--;
            }
            if (currDir == 'U'){
                if (currI < boundaryU){
                    break;
                }
                while (currI >= boundaryU){
                    res.push_back(matrix[currI][currJ]);
                    currI--;
                }
                currDir = 'R';
                boundaryL++;
                currI++;
                currJ++;
            }
        }
        return res;

    }
};