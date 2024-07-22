class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<string> theStack;
        for (string token: tokens){
            if (token == "+"){
                int i1 = stoi(theStack.top());
                theStack.pop();
                int i2 = stoi(theStack.top());
                theStack.pop();
                theStack.push(to_string(i1 + i2));
            }

            else if (token == "-"){
                int i1 = stoi(theStack.top());
                theStack.pop();
                int i2 = stoi(theStack.top());
                theStack.pop();
                theStack.push(to_string(i2 - i1));
            }

            else if (token == "/") {
                int i1 = stoi(theStack.top());
                theStack.pop();
                int i2 = stoi(theStack.top());
                theStack.pop();
                theStack.push(to_string(i2 / i1));
            }

            else if (token == "*") {
                int i1 = stoi(theStack.top());
                theStack.pop();
                int i2 = stoi(theStack.top());
                theStack.pop();
                theStack.push(to_string(i1 * i2));
            }

            else {
                theStack.push(token);
            }
        }
        return stoi(theStack.top());
    }
};