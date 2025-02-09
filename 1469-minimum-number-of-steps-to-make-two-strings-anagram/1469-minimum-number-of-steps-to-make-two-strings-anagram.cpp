class Solution {
public:
    int minSteps(string s, string t) {
        int numSteps = 0;
        for (int i=0; i<26; ++i){
            char currChar = 'a' + i;
            int a = count(s.begin(), s.end(), currChar);
            int b = count(t.begin(), t.end(), currChar);
            if (a > b){
                numSteps += (a - b);
            }
        }
        return numSteps;
    }
};