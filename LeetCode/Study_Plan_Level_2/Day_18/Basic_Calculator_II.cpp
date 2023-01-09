//      Time Complexity  : O(N)
//      Space Complexity : O(N)
class Solution {
public:
    int calculate(string s) {
        //  Base case
        if(s.length() == 0) return 0;

        stack<int> st;
        long long int curr = 0;
        char op = '+';
        for(int i=0;i<s.length();i++){
            char ch = s[i];
            if(isdigit(ch))
                curr = curr*10 + ch - '0';
            if(!isdigit(ch) && ch != ' ' || i == s.length() - 1){
                if(op == '+')
                    st.push(curr);
                else if(op == '-')
                    st.push(-curr);
                else if(op == '*'){
                    int temp = st.top() * curr;
                    st.pop();
                    st.push(temp);
                }
                else if(op == '/'){
                    int temp = st.top() / curr;
                    st.pop();
                    st.push(temp);
                }
                op = ch;
                curr = 0;
            }
        }
        long long int sum = 0;
        while(st.empty() == false){
            sum += st.top();
            st.pop();
        }
        return sum;
    }
};