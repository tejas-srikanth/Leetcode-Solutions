class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        for (int i=0; i<matrix[0].size(); ++i){
            int starti = 0, startj = i;
            int endi = i, endj = 0;
            while (starti < endi && startj > endj){
                std::swap(matrix[starti][startj], matrix[endi][endj]);
                starti++;
                startj--;
                endi--;
                endj++;
            }
        }

        for (int i=1; i<matrix.size(); ++i){
            int starti = i, startj = matrix[0].size() - 1;
            int endi = matrix[0].size() - 1, endj = i;
            while (starti < endi && startj > endj){
                std::swap(matrix[starti][startj], matrix[endi][endj]);
                starti++;
                startj--;
                endi--;
                endj++;
            }
        }

        for (int i=0; i<matrix.size(); ++i){
            std::reverse(matrix[i].begin(), matrix[i].end());
        }

        
    }
};