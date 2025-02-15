class Solution {
public:
    bool isPartition(int n, int target){
        if (target == n){
            return true;
        } else if (n < 10) {
            return false;
        }
        int k = 10;
        while (k < n){
            bool x = isPartition(n / k, target - n % k);
            if (x){
                return true;
            }
            k *= 10;
        }
        return false;

    }
    int punishmentNumber(int n) {
        int x = 0;
        for (int i=1; i<=n; ++i){
            if (isPartition(i*i, i)){
                x += i * i;
                continue;
            }
        }
        return x;
    }
};