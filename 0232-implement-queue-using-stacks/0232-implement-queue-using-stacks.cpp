class MyQueue {
public:
    vector<int> s1, s2;
    MyQueue() {
        s1 = {}; s2 = {};
    }
    
    void emptyStack(vector<int> & s1, vector<int>& s2){
        while (!s1.empty()){
            s2.push_back(s1.back());
            s1.pop_back();
        }
    }
    void push(int x) {
        s1.push_back(x);
    }
    
    int pop() {
        emptyStack(s1, s2);
        int x = s2.back();
        s2.pop_back();
        emptyStack(s2, s1);
        return x;
    }
    
    int peek() {
        emptyStack(s1, s2);
        int x = s2.back();
        emptyStack(s2, s1);
        return x;
    }
    
    bool empty() {
        return s1.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */