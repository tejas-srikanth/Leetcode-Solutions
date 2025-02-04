class Solution {
public:
    string addstrings(string a1, string a2){
        string x = "";
        int carry = 0;
        string n1 = a2;
        string n2 = a1;
        if (a2.length() < a1.length()){
            n1 = a1;
            n2 = a2;
        }
    
        int k = 0;
        for (int i=0; i<n1.length(); i++){
            int j;

            if (i < n2.length()){
                j = (n1[n1.length() - i - 1] - '0') + (n2[n2.length() - i - 1] - '0') + carry;
            } else {
                j = (n1[n1.length() - i - 1] - '0') + carry;
            }
            carry = j / 10;
            x += ('0' + (j % 10));
        }
        if (carry != 0){
            x += (carry + '0');
        }
        std::reverse(x.begin(), x.end());
        return x;
    }

    string mulstringchar(string num1, char num2, int numzeros){
        string x = "";
        int carry = 0;
        if (num1 == "0"){
            return "0";
        }
        for (int i=0; i<numzeros; ++i){
            x += '0';
        }
        for (int i=num1.length()-1; i>=0; i--){
            int j = (num1[i] - '0') * (num2 - '0') + carry;
            carry = j / 10;
            x += ('0' + (j % 10));
        }
        
        if (carry != 0){
            x += ('0' + carry);
        }
        cout << x << endl;
        std::reverse(x.begin(), x.end());
        return x;
    }

    string multiply(string num1, string num2) {
        string finalstring = "0";
        int n2_len = num2.length();
        for (int i=0; i<num2.length(); ++i){
            if (num2[n2_len-i-1] != '0'){
                finalstring = addstrings(finalstring, mulstringchar(num1, num2[n2_len-i-1], i));
            }
        }
        return finalstring;

        
    }
};