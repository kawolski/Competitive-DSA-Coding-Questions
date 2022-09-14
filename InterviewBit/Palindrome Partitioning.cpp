//  Time Complexity  : O(2^N)
//  Space Complexity : O(2^N)
//  Function to check if the string is palindrome : 2 Pointer Approach
bool isPalindrome(string str){
    int low = 0;
    int high = str.size()-1;
    while(low < high){
        if(str[low] != str[high])   return false;
        low++;  high--;
    }
    return true;
}
vector<vector<string> > Solution::partition(string A) {
    vector<vector<string>> ans;
    vector<string> temp;
    int n = A.size();
    
    //  Lambda Function to solve recursively
    function<void(int)> solve = [&](int cur_index)->void{
        
        //  If last index is reached
        if(n <= cur_index){
            ans.push_back(temp);
            return;
        }
        //  Iterate through current index to last index checking for valid Palindromes
        for(int i=cur_index;i<n;i++){
            string cur_string = A.substr(cur_index,i-cur_index+1);
            //  If it's a palindrome
            if(isPalindrome(cur_string)){
                //  Push to temp
                temp.push_back(cur_string);
                //  solve further down the path
                solve(i+1);
                //  Pop from temp
                temp.pop_back();
            }
        }
        
    };
    //  Function call from index 0
    solve(0);
    
    return ans;
}
