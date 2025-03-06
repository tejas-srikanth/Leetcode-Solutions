class Solution {
public:
    long long coloredCells(int n) {
        long long x = (long long)n;
        return (long long)(1 + 2 * x * (x - 1));
    }
};