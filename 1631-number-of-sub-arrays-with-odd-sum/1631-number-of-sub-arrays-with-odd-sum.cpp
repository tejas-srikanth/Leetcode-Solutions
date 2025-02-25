class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        int numOdd = 0;
        int numEven = 1;
        int acc = 0;
        int totalOdd = 0;
        int MOD = 1000000000 + 7;
        for (int k: arr){
            acc += k;
            if (acc % 2 == 0){
                totalOdd += numOdd;
            } else {
                totalOdd += numEven;
            }
            numOdd += (acc % 2);
            numEven += (1 - acc % 2);
            totalOdd = totalOdd % MOD;
        }
        return totalOdd;
    }
};