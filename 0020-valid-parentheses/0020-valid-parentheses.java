import java.util.Stack;
class Solution {
    public boolean isValid(String s) {
        Stack<Character> x = new Stack<Character>();
        for (int i=0; i<s.length(); ++i){
            if (s.charAt(i) == '(' || s.charAt(i) == '{' || s.charAt(i) == '['){
                x.push(s.charAt(i));
            } else {
                if (x.size() == 0){
                    return false;
                }
                char lastEl = x.peek();
                if ((lastEl == '(' && s.charAt(i) == ')') || (lastEl == '[' && s.charAt(i) == ']') || (lastEl == '{' && s.charAt(i) == '}')){
                    x.pop();
                } else {
                    return false;
                }
            }
        }
        return x.size() == 0;
        
    }
}