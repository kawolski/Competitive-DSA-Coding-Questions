class MinStack {
public:
    stack<pair<int,int>> st;
    MinStack() {
        //  Empty the stack
        while(st.empty() == false)
            st.pop();
    }
    
    //      Time Complexity  : O(1)
    //      Space Complexity : O(N)
    void push(int val) {
        int mini = val;
        if(st.empty() == false)
            mini = min(mini,st.top().second);
        st.push({val,mini});
    }
    
    //      Time Complexity : O(1)
    void pop() {
        //  Pop if element present
        if(st.empty() == false)
            st.pop();
    }
    
    //      Time Complexity : O(1)
    int top() {
        //  Return top if element present
        if(st.empty() == true)
            return -1;
        else
            return st.top().first;
    }
    
    //      Time Complexity : O(1)
    int getMin() {
        //  getMin if element present
        if(st.empty() == true)
            return -1;
        else
            return st.top().second;
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