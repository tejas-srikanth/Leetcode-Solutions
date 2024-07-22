class MinStack {
public:
    vector<int> theStack;
    vector<int> minStack;
    MinStack() {
    }
    
    void push(int val) {
        theStack.push_back(val);
        if (minStack.empty() || val <= minStack.back()){
            minStack.push_back(val);
        }
    }
    
    void pop() {
        int top_elt = theStack.back();
        if (top_elt == minStack.back()){
            minStack.pop_back();
        }
        theStack.pop_back();
    }
    
    int top() {
        return theStack.back();
    }
    
    int getMin() {
        return minStack.back();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */