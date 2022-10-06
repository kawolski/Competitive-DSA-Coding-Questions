//      Time Complexity  : O(M*M)
//      Space Complexity : O(M+N)
//      where   M = num1 length
//              N = num2 length
class Solution {
public:
    string multiply(string num1, string num2) {
        int m = num1.size();
        int n = num2.size();
        
        //  Base cases
        if(m == 0 || n == 0 || num1 == "0" || num2 == "0")  return "0";
        if(num1 == "1") return num2;
        if(num2 == "1") return num1;
        
        //  Compute
        vector<int> result(m+n,0);
        
        for(int i=m-1;i>=0;i--){
            for(int j=n-1;j>=0;j--){
                int product = (num1[i]-'0')*(num2[j]-'0');  //  Multiply the digits
                product += result[i+j+1];                   //  Add the Carry
                result[i+j+1] = product%10;                 //  Replace with one's position
                result[i+j] += product/10;                  //  Add carry to next position
            }
            
        }
        string ans = "";
        //  Remove 0's from the starting of the number and make the ans
        for(int ele : result){
            if(ele == 0 and ans.size() == 0)
                continue;
            ans = ans + to_string(ele);
        }
        return ans;
    }
};