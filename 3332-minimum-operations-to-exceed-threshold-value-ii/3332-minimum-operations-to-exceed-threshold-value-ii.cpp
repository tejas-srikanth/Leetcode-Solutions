class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        priority_queue<long, vector<long>, std::greater<long>> numQueue;
        for (int x: nums){ numQueue.push(x); }
        int numOp = 0;
        while (numQueue.size() >= 2){
            long a = numQueue.top();
            numQueue.pop();
            long b = numQueue.top();
            cout << a << " " << b << endl;
            numQueue.pop();
            if (a >= k){
                break;
            }

            numQueue.push(a * 2 + b);
            numOp++;
        }
        return numOp;
    }
};