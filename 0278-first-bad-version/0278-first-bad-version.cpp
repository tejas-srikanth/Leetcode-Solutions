// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        unsigned long st = 1;
        unsigned long end = n;
        unsigned long mid = 2;
        if (isBadVersion(st)){
            return 1;
        } else if (n > 1 && isBadVersion(n) && !isBadVersion(n - 1)){
            return n;
        } else {
            while (st <= end && mid >= 2){
                mid = (st + end) / 2;
                if (isBadVersion(mid) && !isBadVersion(mid - 1)){
                    return mid;
                } else if (!isBadVersion(mid)){
                    st = mid + 1;
                } else {
                    end = mid - 1;
                }
            }
        }
        return -1;
    }
};