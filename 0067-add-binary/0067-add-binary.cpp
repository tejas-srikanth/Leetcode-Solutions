class Solution {
public:
    string addBinary(string a, string b) {
        int bptr = b.size() - 1;
        int aptr = a.size() - 1;
        string x = "";
        int carry = 0;
        int bval, aval;
        while (bptr >= 0 || aptr >= 0){
            if (bptr < 0){
                bval = 0;
            } else {
                bval = b[bptr] - '0';
            }
            if (aptr < 0){
                aval = 0;
            } else {
                aval = a[aptr] - '0';
            }
            if (bval && aval){
                x += '0' + carry;
                carry = 1;
            } else if (aval || bval) {
                x += '0' + !carry;
            } else {
                x += '0' + carry;
                carry = 0;
            }
            aptr--;
            bptr--;

        }
        if (carry){
            x += '1';
        }
        reverse(x.begin(), x.end());
        return x;
    }
};