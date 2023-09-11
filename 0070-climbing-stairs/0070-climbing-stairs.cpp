class Solution {
public:
    int climbStairs(int n) {
        if (n == 1){
            return 1;
        } else if (n == 2){
            return 2;
        } else {
            int f = 1;
            int s = 2;
            int tmp;
            for (int i=3; i<=n; ++i){
                tmp = f + s;
                f = s;
                s = tmp;
            }
            return s;
        }
    }
};