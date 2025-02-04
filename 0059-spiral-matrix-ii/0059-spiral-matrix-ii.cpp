class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> spiral(n, vector<int>(n, 0));
        int numElFilled = 0;
        int currI = 0, currJ = 0;
        while (numElFilled < n * n){
            while (currJ <= n-1 && spiral[currI][currJ] == 0){
                spiral[currI][currJ] = numElFilled + 1;
                currJ++;
                numElFilled++;
            }
            currJ--;
            currI++;
            while (currI <= n-1 && spiral[currI][currJ] == 0){
                spiral[currI][currJ] = numElFilled + 1;
                currI++;
                numElFilled++;
            }
            currI--;
            currJ--;
            while (currJ >= 0 && spiral[currI][currJ] == 0){
                spiral[currI][currJ] = numElFilled + 1;
                currJ--;
                numElFilled++;
            }
            currJ++;
            currI--;
            while (currI >= 0 && spiral[currI][currJ] == 0){
                spiral[currI][currJ] = numElFilled + 1;
                currI--;
                numElFilled++;
            }
            currI++;
            currJ++;
            
        }
        return spiral;
    }
};