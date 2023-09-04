class Solution {
public:
    int minFlips(int a, int b, int c) {
        cout << __builtin_popcount((a&b)^(c)) << " " <<  __builtin_popcount((a & b) & (~c)) * 2;
        return __builtin_popcount(~(a|b)&c) + __builtin_popcount((a^b)&~c) +__builtin_popcount((a & b) & (~c)) * 2;
    }
};