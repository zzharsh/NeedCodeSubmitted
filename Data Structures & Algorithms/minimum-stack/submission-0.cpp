class MinStack {
public:
    int min1, min2;
    stack<int> Sv, Sm;
    MinStack() {
        Sm.push(INT_MAX);
    }
    
    void push(int val) {
        if(Sm.top() > val)
        {
            Sm.push(val);
        }
        else
        {
            Sm.push(Sm.top());
        }
        Sv.push(val);
    }
    
    void pop() {
        Sv.pop();
        Sm.pop();
    }
    
    int top() {
        return Sv.top();
    }
    
    int getMin() {
        return Sm.top();
    }
};
