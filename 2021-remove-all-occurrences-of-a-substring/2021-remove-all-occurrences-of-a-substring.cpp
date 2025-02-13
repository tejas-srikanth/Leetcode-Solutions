class Solution {
public:
    string removeOccurrences(string s, string part) {
        string stringStack = "";
        if (part.length() > s.length()){
            return s;
        }

        for (char c: s){
            stringStack += c;
            if (stringStack.length() >= part.length() && stringStack.substr(stringStack.length() - part.length(), part.length()) == part){
                for (int i=0; i<part.length(); ++i){
                    stringStack.pop_back();
                }
            }
        }
        return stringStack;
    }
};