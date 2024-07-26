class Solution {
public:
    int mxCount(vector<int> x){
        int currMax = -1;
        int tot = 0;
        for (int j: x){
            tot += j;
            currMax = max(j, currMax);
        }
        return tot - currMax;
    }
    int characterReplacement(string s, int k) {
        int st = 0;
        int ed = 0;
        vector<int> charArr(26, 0);
        charArr[s[0] - 'A']++;
        int longestWindow = 1;
        while (ed < s.length()-1){
            ed++;
            charArr[s[ed] - 'A']++;
            if (mxCount(charArr) > k){
                
                charArr[s[st] - 'A']--;
                st++;
            }
            else {
                longestWindow = max(ed - st + 1, longestWindow);
            }
            
        }
        return longestWindow;
    }
};