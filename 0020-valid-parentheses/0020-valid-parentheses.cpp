class Solution {
public:
    bool isValid(string s) {
        vector<int> theStack;
        map<char, char> m = {{')', '('}, {']', '['}, {'}', '{'}};
        for (char c: s){
            if (m.find(c) != m.end()){
                if (theStack.empty() || theStack.back() != m[c]){
                    return false;
                } else {
                    theStack.pop_back();
                }
            } else {
                theStack.push_back(c);
            }
        }
        return theStack.empty();
    }
};