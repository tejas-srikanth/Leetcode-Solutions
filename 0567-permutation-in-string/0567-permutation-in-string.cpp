class Solution {
public:

    bool checkInclusion(string s1, string s2) {
        vector<int> s1_arr(26);
        vector<int> s2_arr(26);
        for (char c: s1){
            s1_arr[c - 'a']++;
        }
        if (s2.length() < s1.length()){
            return false;
        }

        int winStart = 0;
        int winEnd = 0;
        for (int i=0; i<s1.length(); ++i){
            char c = s2[winEnd];
            s2_arr[c - 'a']++;
            winEnd++;
        }
        winEnd--;
        while (winEnd < s2.length()-1){
            if (s1_arr == s2_arr){
                return true;
            } else {
                s2_arr[s2[winStart] - 'a']--;
                winStart++;
                winEnd++;
                s2_arr[s2[winEnd] - 'a']++;
            }
        }
        return s1_arr == s2_arr;
    }
};