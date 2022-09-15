//      Time Complexity  : O(1)
//      Space Complexity : O(N)
stack<pair<int,int>> st;
MinStack::MinStack() {
    //  Empty the stack
    while(st.size())
        st.pop();
}

void MinStack::push(int x) {
    //  If stack is empty push {x,minimum element till now}
    if(st.empty())
        st.push({x,x});
    //  Else push {x, minimum of x and minimum element till previous step}
    else
        st.push({x,min(x,st.top().second)});
}

void MinStack::pop() {
    //  If stack is not empty pop the topmost element
    if(st.empty() == false)
        st.pop();
}

int MinStack::top() {
    if(st.empty() == false)
        return st.top().first;
    else
        return -1;
}

int MinStack::getMin() {
    //  If stack is not empty return current minimum element
    if(st.empty() == false)
        return st.top().second;
    else
        return -1;
}