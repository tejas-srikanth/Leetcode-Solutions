class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int numWhite = 0;
        for (int i=0; i<k; ++i){
            numWhite += (blocks[i] == 'W'); 
        }
        int bestTurns = numWhite;
        for (int i=1; i<blocks.size() - k + 1; ++i){
            numWhite -= (blocks[i - 1] == 'W');
            numWhite += (blocks[i + k - 1] == 'W');
            bestTurns = min(bestTurns, numWhite);
        }
        return bestTurns;

    }
};