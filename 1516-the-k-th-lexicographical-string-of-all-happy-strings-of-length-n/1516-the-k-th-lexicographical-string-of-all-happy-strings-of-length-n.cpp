class Solution {
public:
    string getHappyString(int n, int k) {
        vector<int> pow2 = {1, 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024, 2048};
        int numHappy = 3 * pow2[n-1];
        cout << numHappy << endl;
        string retStr = "";
        k = k - 1;
        if (k >= numHappy){
            return "";
        } else {
            int i = n;
            if (k < pow2[i-1]){
                retStr += 'a';
            } else if (k < 2 * pow2[i-1]){
                retStr += 'b';
            } else {
                retStr += 'c';
            }
            k = k % pow2[i - 1];
            i = i - 1;
            
            while (i >= 1){
                char last = retStr.back();
                if (k < pow2[i - 1]){
                    if (last == 'a'){
                        retStr += 'b';
                    } else {
                        retStr += 'a';
                    }
                } else {
                    if (last == 'c'){
                        retStr += 'b';
                    } else {
                        retStr += 'c';
                    }
                }
                k = k % pow2[i-1];
                i = i - 1;
            }
        }
        return retStr;
    }
};