class Solution {
public:
    void clearArr(int* x){
        for (int i=0; i<26; ++i){
            x[i] = 0;
        }
    }
    int partitionString(string s) {
        int arr[26] = {0};
        int cnt = 1;
        for (char c: s){
            if (arr[c - 'a'] == 1){
                clearArr(arr);
                cnt++;
            }
            arr[c - 'a']++;
        }
        return cnt;
    }
};