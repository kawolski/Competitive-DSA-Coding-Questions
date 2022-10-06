//      Time Complexity  : O(N^2)
//      Space Complexity : O(1)
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int R = matrix.size();
        int C = matrix[0].size();
        vector<vector<bool>> visited(R,vector<bool>(C,false));
        vector<int> res;
        //  Lambda function to find parameter elements of given matrix range
        function<void(int,int,int,int)> solve = [&](int rmin,int rmax,int cmin,int cmax)->void{
            //  Return if range overlaps
            if(rmin > rmax ||  cmin > cmax)
                return;
            //  Top     :   Left -> Right
            for(int c=cmin;c <= cmax;c++)
                if(visited[rmin][c] == false)
                    visited[rmin][c] = true,res.push_back(matrix[rmin][c]);
            //  Right   :   Top -> Bottom
            for(int r=rmin;r <= rmax;r++)
                if(visited[r][cmax] == false)
                    visited[r][cmax] = true,res.push_back(matrix[r][cmax]);
            //  Bottom  :   Right -> Left
            for(int c=cmax;c >= cmin;c--)
                if(visited[rmax][c] == false)
                    visited[rmax][c] = true,res.push_back(matrix[rmax][c]);
            //  Left    :   Bottom -> Top
            for(int r=rmax;r >= rmin;r--)
                if(visited[r][cmin] == false)
                    visited[r][cmin] = true,res.push_back(matrix[r][cmin]);
            //  Call the function on inside matrix
            solve(rmin+1,rmax-1,cmin+1,cmax-1);
            
        };
        
        solve(0,R-1,0,C-1);
        return res;
    }
};