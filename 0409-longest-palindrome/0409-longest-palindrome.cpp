class Solution {
public:
    int longestPalindrome(string s) {
        int chArr[52] = {0};
        for (char c: s){
            if (c - 'a' >= 0){
                chArr[c - 'a']++;
            } else {
                chArr[26 + c - 'A']++;
            }
        }
        int palLen = 0;
        bool usedOne = false;
        for (int i=0; i<52; ++i){
            if (chArr[i] % 2 == 0){
                palLen+= chArr[i];
            } else {
                if (!usedOne){
                    palLen += chArr[i];
                    usedOne = true;
                } else {
                    palLen += chArr[i] - 1;
                }
            }
        }
        return palLen;
    }
};