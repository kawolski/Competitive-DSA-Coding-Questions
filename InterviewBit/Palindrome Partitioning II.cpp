//  Time Complexity  : O(N^2)
//  Space Complexity : O(N^2)

int Solution::minCut(string A) {
    //  Base Case
    if(A.size() == 1 || A.size() == 0)  return 0;
    
    int n = A.size();
    vector<vector<bool>> isPalin(n,vector<bool>(n,false));
    
    //  Make isPalindrome dp array
    for(int g=0;g<n;g++){
        for(int i=0;i<n-g;i++){
            int j = i+g;
            //  If gap is 0  ;  ie : i == j
            if(g == 0)
                isPalin[i][j] = true;
            //  If gap == 1 just check both characters
            else if(g == 1){
                isPalin[i][j] = (A[i] == A[j]);
            }
            //  Else if edge charactars are same and the center substring is palindrome then whole string is palindrome
            else{
                if(A[i] == A[j] && isPalin[i+1][j-1] == true)
                    isPalin[i][j] = true;
                else
                    isPalin[i][j] = false;
            }
        
        }
    }
    vector<int> res(n,0);
    
    for(int i=1;i<n;i++){
        //  If substring(0,i) is already a palindrome then no partition is needed
        if(isPalin[0][i] == true){
            res[i] = 0;
            continue;
        }
        //  Else compute minimum partitions needed
        int mini = INT_MAX;
        for(int j=i;j>0;j--){
            if(isPalin[j][i] == true){
                if(res[j-1] < mini)
                    mini = res[j-1];
            }
        }
        //  Minimum partitions needed for substrings made from string(0,i-1) + 1
        res[i] = mini+1;
    }
    
    return res[n-1];
}
