//      Time Complexity  : O(RxC)
//      Space Complexity : O(C)
class Solution {
public:
    vector<int> findBall(vector<vector<int>>& grid) {
        int R = grid.size();
        int C = grid[0].size();
        vector<int> res(C);
        //  Initialization
        for(int i=0;i<C;i++)
            res[i] = i;
        
        //  Compute
        
        for(int r=0;r<R;r++){
            for(int c=0;c<C;c++){
                //  Ball Stuck Check
                if(res[c] == -1)
                    continue;
                //  Current Block Throws Ball to the Right
                else if(grid[r][res[c]] == 1){
                    //  Next Block Throws Ball to the Right : OK
                    if(res[c]+1 < C && grid[r][res[c]+1] == 1){
                        res[c] = res[c]+1;
                    }
                    //  Next Block Throws Ball to the Left or Wall : Stuck
                    else
                        res[c] = -1;
                }
                //  Current Block Throws Ball to the Left
                else{
                    //  Previous Block Throws Ball to the Left : OK
                    if(res[c]-1 >= 0 && grid[r][res[c]-1] == -1)
                        res[c] = res[c]-1;
                    //  Previous Block Throws Ball to the Right or Wall : Stuck
                    else
                        res[c] = -1;
                }
            }
        }
        
        
        return res;
    }
};