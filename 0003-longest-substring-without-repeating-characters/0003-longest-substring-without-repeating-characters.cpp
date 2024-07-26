class Solution {
public:
    bool ist(unordered_map<char, int>& x){
        for (pair<char, int> k: x){
            if (k.second > 1) return true;
        }
        return false;
    }
    int lengthOfLongestSubstring(string s) {
        if (s.length() < 2){
            return s.length();
        }
        int winStart = 0;
        int winEnd = 0;
        unordered_map<char, int> charArr;
        charArr[s[winStart]] = 1;
        int longestLength = 1;
        while (winEnd < s.length() - 1){
            winEnd++;
            if (charArr.find(s[winEnd]) == charArr.end()){
                charArr[s[winEnd]] = 0;
            }
            charArr[s[winEnd]]++;
            if (ist(charArr)) {
                charArr[s[winStart]]--;
                winStart++;
            } else {
                longestLength = max(winEnd - winStart + 1, longestLength);
            }

        }
        return longestLength;
    }
};