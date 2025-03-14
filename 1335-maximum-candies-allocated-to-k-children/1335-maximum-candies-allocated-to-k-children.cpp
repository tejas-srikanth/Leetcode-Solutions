class Solution {
public:
    bool canDivide(vector<int>& candies, int numCandies, long long numChildren){
        if (numCandies == 0){
            return true;
        }
        long long total = 0;
        for (int candy: candies){
            total += (candy / numCandies);
        }
        return total >= numChildren;
    }
    int maximumCandies(vector<int>& candies, long long k) {
        int lo = 0;
        int hi = *std::max_element(candies.begin(), candies.end()) + 1;
        while (lo < hi){
            int mid = (lo + hi + 1) / 2;
            if (canDivide(candies, mid, k)){
                lo = mid;
            } else {
                hi = mid - 1;
            }
        }
        return lo;
    }
};