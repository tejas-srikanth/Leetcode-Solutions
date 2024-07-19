class Solution {
public:
    bool isAnagram(string s, string t) {
        int chararr[26];
        for (char c: s){
            chararr[c - 'a']++;
        }

        for (char c: t){
            chararr[c - 'a']--;
        }

        for (int i=0; i<26; i++){
            if (chararr[i] != 0){
                return false;
            }
        }
        return true;
    }
};