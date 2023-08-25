class Solution {
public:
    string removeStars(string s) {
        string k = "";
        for (char c: s){
            if (c == '*'){
                k.pop_back();
            } else {
                k += c;
            }
        }
        return k;
    }
};