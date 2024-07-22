class Solution {
public:
    vector<string> generateParenthesisHelper(int n, int m){
        vector<string> res;

        
        if (n == 0){
            string s(m, ')');
            return {s};
        }
        if (m-1 >= n){
            vector<string> fRes = generateParenthesisHelper(n, m-1);
            for (string st: fRes){
                res.push_back(")" + st);
            }
        }

        vector<string> otherRes = generateParenthesisHelper(n-1, m);
        for (string st: otherRes){
            res.push_back("(" + st);
        }
        return res;

    }
    vector<string> generateParenthesis(int n) {
        string s(5, '(');
        cout << s << endl;
        return generateParenthesisHelper(n, n);
    }
};