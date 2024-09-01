class Solution {
public:
    bool isPalindrome(string s){
        int st = 0;
        int ed = s.length() - 1;
        while (st <= ed){
            if (s[st] != s[ed]){
                return false;
            }
            st++;
            ed--;
        }
        return true;
    }
    vector<vector<string>> partition(string s) {
        string acc = "";
        if (s.length() == 1){
            return {{s}};
        } else if (s.length() == 0){
            return {{}};
        }
        vector<vector<string>> res;
        for (int i=s.length() - 1; i>= 0; --i){
            acc += s[i];
            if (isPalindrome(acc)){
                vector<vector<string>> all = partition(s.substr(0, i));
                for (vector<string> x: all){
                    x.push_back(acc);
                    res.push_back(x);
                }
            }
        }
        return res;
    }
};