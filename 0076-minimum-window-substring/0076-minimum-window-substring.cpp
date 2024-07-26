class Solution {
public:
    int convertIndex(char c){
        if (c - 'A' >= 0 && c - 'A' < 26){
            return c - 'A';
        } else {
            return 26 + c - 'a';
        }
    }
    bool ge(vector<int>& s, vector<int>& t){
        for (int i=0; i<s.size(); ++i){
            if (s[i] < t[i]) return false;
        }
        return true;
    }
    string minWindow(string s, string t) {
        vector<int> t_arr(52, 0);
        vector<int> s_arr(52, 0);

        for (char c: t){
            t_arr[convertIndex(c)]++;
        }
        int st = 0;
        int ed = 0;
        s_arr[convertIndex(s[0])]++;
        int mws = s.length() + 1;
        int minStart = -1;
        if (s.length() < t.length()){
            return "";
        }
        while (ed < s.length()){
            if (ge(s_arr, t_arr)){
                mws = min(ed - st + 1, mws);
                if (mws == ed - st + 1) minStart = st;
                s_arr[convertIndex(s[st])]--;
                st++;
            }

            else {
                if (ed == s.length() - 1){
                    break;
                }
                ed++;
                s_arr[convertIndex(s[ed])]++;
            }
        }
        if (minStart == -1) {
            return "";
        } else {
            return s.substr(minStart, mws);
        }
    }
};