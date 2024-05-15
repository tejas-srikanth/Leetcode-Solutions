class Solution {
public:
    bool isCorresponding(char a, char b){
        return (a == '{' && b == '}') || (a == '[' && b == ']') || (a == '(' && b == ')');
    }
    bool isValid(string s) {
        stack<char> theStack;
        for (char c: s){
            if (c == ']' || c == ')' || c == '}'){
                if (theStack.empty() || !isCorresponding(theStack.top(), c)){
                    return false;
                } else {
                    theStack.pop();
                }
            } else {
                theStack.push(c);
            }
        }
        return theStack.empty();
    }
};