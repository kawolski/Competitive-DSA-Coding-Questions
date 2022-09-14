//  Time Complexity  : O(N)
//  Space Complexity : O(1)
int Solution::isPalindrome(string A) {
    //  Modify the same String into new valid string
    
    //  Update valid character's position in the string by making them contiguous
    //  ie : removing spaces, cases and all special characters
    
    int n = A.size();
    int i = 0;
    
    for(int j=0;j<n;j++){
        char ele = A[j];
        //  ele : [a,z]
        if(96 < int(ele) && int(ele) < 123)
            A[i++] = ele;
        //  ele : [A,Z]
        else if( 64 < int(ele) && int(ele) < 91)
            A[i++] = (ele + 32);
        //  ele : [0,9]
        else if(47 < int(ele) && int(ele) < 58)
            A[i++] = ele;
        
        //  Discard other characters
    }
    
    //  Start from 0 and valid index i-1
    int low = 0;
    int high = i-1;
    //  Two pointers approach
    while(low < high){
        if(A[low] != A[high])
            return 0;
        low++;  high--;
    }
    return 1;
}
