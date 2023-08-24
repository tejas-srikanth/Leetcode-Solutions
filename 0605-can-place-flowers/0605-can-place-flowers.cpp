class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int numFlowers = 0;
        bool canPlace = true;
        for (int i=0; i<flowerbed.size(); ++i){
            cout << i << " ";
            if (flowerbed[i]){
                if ((i != 0) && flowerbed[i - 1]){
                    numFlowers--;
                }
                continue;
            } else {
                if (i == 0){
                    flowerbed[i] = 1;
                    numFlowers++;
                } else {
                    if (!flowerbed[i - 1]){
                        flowerbed[i] = 1;
                        numFlowers++;
                    }
                }
            }
        }
        return numFlowers >= n;
    }
};