class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int mag[26] = {0};
        int rN[26] = {0};
        int x;
        for (char rnc: ransomNote){
            x = rnc - 'a';
            rN[x]++;
        }

        for (char mc: magazine){
            x = mc - 'a';
            cout << mc << ' ';
            mag[mc - 'a']++;
        }

        for (int i=0; i<26; ++i){
            if (mag[i] < rN[i]){
                return false;
            }
        }
        return true;
    }
};