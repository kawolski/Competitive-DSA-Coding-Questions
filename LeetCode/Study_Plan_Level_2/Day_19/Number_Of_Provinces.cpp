//      Time Complexity  : O(N)
//      Space Complexity : O(N)
class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<bool> visited(n,false);
        int provinces = 0;
        function<void(int)> dfs = [&](int city)->void{
            //  Return if visited
            if(visited[city] == true)
                return;
            //  Mark as visited
            visited[city] = true;
            //  DFS the connected cities
            for(int i=0;i<n;i++)
                if(isConnected[city][i] == 1)
                    dfs(i);
        };
        for(int i=0;i<n;i++){
            if(visited[i] == false){
                provinces++;
                dfs(i);
            }
        }
        return provinces;
    }
};