//      Time Complexity  : O(N)
//      Space Complexity : O(N)
string Solution::convert(string A, int B) {
    //  Base Case
    if(B == 1)
        return A;
    int n = A.size();
    //  For efficiency assign the required memory at the begining, ( res = A )
    string res = A;
    //  Index for new string
    int k = 0;
    for(int i=0;i<B;i++){
        //  Number of rows above current row
        int down = B-i-1;
        //  Number of rows below current row
        int up = i;
        //  If first row
        if(up == 0){
            int ind = i;
            while(ind < n){
                res[k++] = A[ind];
                //  Skip 2 times below elements
                ind += 2*down;
            }
        }
        //  Rows in the middle
        else if(up && down){
            int ind = i;
            while(ind < n){
                res[k++] = A[ind];
                //  Skip 2 times bottom elements
                ind += 2*down;
                if(ind < n){
                    res[k++] = A[ind];
                    //  Skip 2 times above elements
                    ind += 2*up;
                }
            }
        }
        //  If last row
        else if(down == 0){
            int ind = i;
            while(ind < n){
                res[k++] = A[ind];
                //  Skip 2 times above elements
                ind += 2*up;
            }
        }
    }
    return res;
}