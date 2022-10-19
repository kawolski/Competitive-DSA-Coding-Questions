class MyQueue {
public:
    stack<int> st1;
    MyQueue() {
        //  Empty both the stacks
        while(st1.empty() == false)
            st1.pop();
    }
    
    void push(int x) {
        st1.push(x);
    }
    
    int pop() {
        //  If there is no element in the stack
        if(st1.empty() == true)
            return -1;
        
        stack<int> st2;
        while(st1.empty() == false)
            st2.push(st1.top()),st1.pop();
        
        //  Save & Remove front of queue
        int res = st2.top();
        st2.pop();
        
        while(st2.empty() == false)
            st1.push(st2.top()),st2.pop();
        
        //  Return front of queue
        return res;
    }
    
    int peek() {
        //  If there is no element in the stack
        if(st1.empty() == true)
            return -1;
        
        stack<int> st2;
        while(st1.empty() == false)
            st2.push(st1.top()),st1.pop();
        
        //  Save front of queue
        int res = st2.top();
        
        while(st2.empty() == false)
            st1.push(st2.top()),st2.pop();
        
        //  Return front of queue
        return res;
    }
    
    bool empty() {
        return st1.empty();
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