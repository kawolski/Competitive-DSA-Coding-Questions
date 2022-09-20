//*********************Using KMP Algorithm*************************

//      Time Complexity  : O(N+M)
//      Space Complexity : O(M)
//      where N = length(haystack)
//            M = length(needle)
int Solution::strStr(const string A, const string B) {
    //  Base cases
    if(A.empty())   return -1;
    //  Compute the pattern
    vector<int> needle(B.size(),0);
    for(int i=1,j=0;i<B.size();){
        //  If prefix == suffix
        if(B[j] == B[i]){
            needle[i] = j+1;
            j++;
            i++;
        }
        //  Else start checking from the index of last matched needle value
        else{
            //  needle[j-1]  iff j != 0
            if(j == 0){
                needle[i] = 0;
                i++;
            }else{
                j = needle[j-1];
            }
        }
    }
    for(int i=0,j=0;i<A.size();){
        //  If needle index matches haystack index inreament both
        if(B[j] == A[i]){
            j++;
            i++;
        }
        else{
            //  Increament haystack index if reached needle's starting point
            if(j == 0){
                i++;
            }
            //  Else decreament needle's index to last matched index position
            else{
                j = needle[j-1];
            }
        }
        //  Check if no more needle index left to match   ie :  Needle found in haystack
        if(j == B.size())
            //  Return the starting position of the needle in haystack
            return i-B.size();
    }
    //  Not found
    return -1;
}
