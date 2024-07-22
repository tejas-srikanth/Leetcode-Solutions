class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> theStack;
        for (string token: tokens){
            if (token == "+"){
                int i1 = theStack.top();
                theStack.pop();
                int i2 = theStack.top();
                theStack.pop();
                theStack.push(i1 + i2);
            }

            else if (token == "-"){
                int i1 = theStack.top();
                theStack.pop();
                int i2 = theStack.top();
                theStack.pop();
                theStack.push(i2 - i1);
            }

            else if (token == "/") {
                int i1 = theStack.top();
                theStack.pop();
                int i2 = theStack.top();
                theStack.pop();
                theStack.push(i2 / i1);
            }

            else if (token == "*") {
                int i1 = theStack.top();
                theStack.pop();
                int i2 = theStack.top();
                theStack.pop();
                theStack.push(i1 * i2);
            }

            else {
                theStack.push(stoi(token));
            }
        }
        return theStack.top();
    }
};