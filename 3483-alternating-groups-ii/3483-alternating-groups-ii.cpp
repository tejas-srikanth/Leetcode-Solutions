class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
        int winEnd = (k - 1) % colors.size();
        int numAlternating = 1;
        for (int i=1; i<=winEnd; i++){
            if (colors[i] == colors[i-1]){
                numAlternating = 1;
            } else {
                numAlternating++;
            }
        }
        int numberSeqs = 0;
        for (int i=0; i<colors.size(); ++i){
            cout << i << " " << numAlternating << endl;
            if (numAlternating == k){
                numberSeqs++;
            }
            int j = (i + k) % colors.size();
            if (colors[j] == colors[(i + k - 1) % colors.size()]){
                numAlternating = 1;
            } else {
                numAlternating++;
            }

            if (colors[i % colors.size()] != colors[(i + 1) % colors.size()]
             && numAlternating == k + 1){
                numAlternating--;
            }
        }
        return numberSeqs;

    }
};