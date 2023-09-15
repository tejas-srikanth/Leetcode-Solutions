class Solution {
public:
    int kthFactor(int n, int k) {
        int fC = 0;
        for (int i=1; i<=n; ++i){
            if (n % i == 0){
                fC++;
            }
            if (fC == k){
                return i;
            }
        }
        return -1;

    }
};