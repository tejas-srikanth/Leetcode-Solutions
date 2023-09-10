class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> vs(26, 0);
        for (char c: s){
            vs[c - 'a']++;
        }
        for (char c: t){
            vs[c - 'a']--;
        }
        for (int x: vs){
            if (x != 0){
                return false;
            }
        }
        return true;
    }
};