//      Time Complexity  : O(N^2)
//      Space Complexity : O(N^2)
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        const int MAXI = 100;
        int r = grid.size();
        int c = grid[0].size();
        vector<vector<int>> visited(r,vector<int>(c,-1));
        //  Initialization
        //  MAXI    :   Not Reached
        //  0       :   Initially Rotton Oranges
        //  -1      :   Empty Cell
        queue<pair<int,int>> q;
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(grid[i][j] == 1)                         //  Fresh Oranges
                    visited[i][j] = MAXI;
                else if(grid[i][j] == 2)                    //  Rotton Oranges
                    visited[i][j] = 0,q.push({i,j});
            }
        }
        
        //  BFS         :       Queue of Rotton Oranges
        while(q.empty() == false){
            //  Get and Pop
            auto front = q.front();
            q.pop();
            //  Check Neighbors
            int x = front.first;
            int y = front.second;
            //  If :
            //      1. In Range
            //      2. Has Fresh Orange That Has Not Been Visited
            
            //  x+1,y
            if(x+1 < r && grid[x+1][y] == 1 && (visited[x+1][y] == MAXI))
                visited[x+1][y] = min(visited[x+1][y],visited[x][y]+1),q.push({x+1,y});
            //  x-1,y
            if(0 <= x-1 && grid[x-1][y] == 1 && (visited[x-1][y] == MAXI))
                visited[x-1][y] = min(visited[x-1][y],visited[x][y]+1),q.push({x-1,y});
            // //  x,y+1
            if(y+1 < c && grid[x][y+1] == 1 && (visited[x][y+1] == MAXI))
                visited[x][y+1] = min(visited[x][y+1],visited[x][y]+1),q.push({x,y+1});
            // //  x,y-1
            if(0 <= y-1 && grid[x][y-1] == 1 && (visited[x][y-1] == MAXI))
                visited[x][y-1] = min(visited[x][y-1],visited[x][y]+1),q.push({x,y-1});
        }
        
        int ans = 0;
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                ans = max(ans,visited[i][j]);
            }
        }
        
        //  Return maximum time if all oranges will rot
        return ans == MAXI ? -1 : ans;
    }
};