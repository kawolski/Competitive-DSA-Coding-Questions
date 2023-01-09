//      Time Complexity     :   O(N)
//      Space Complexity    :   O(N)
class Solution {
    bool detectCycle_util(vector<vector<int>> &adj,vector<int> &visited, int v){
        if(visited[v] == 1)
            return true;
        if(visited[v] == 2)
            return false;
        
        visited[v] = 1;
        for(int i=0;i<adj[v].size();i++)
            if(detectCycle_util(adj,visited,adj[v][i]))
                return true;
        visited[v] = 2;
        return false;
    }
    bool detectCycle(vector<vector<int>> &adj,int n){
        vector<int> visited(n,0);
        for(int i=0;i<n;i++)
            if(!visited[i])
                if(detectCycle_util(adj,visited,i))
                    return true;
        return false;
    }
    void dfs(vector<vector<int>> &adj,int v,vector<bool> & visited,stack<int> &st){
        visited[v] = true;
        for(int i=0;i<adj[v].size();i++)
            if(!visited[adj[v][i]])
                dfs(adj,adj[v][i],visited,st);
        st.push(v);
    }
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        for(auto ele : prerequisites)
            adj[ele[1]].push_back(ele[0]);
        
        vector<int> ans;
        if(detectCycle(adj,numCourses))
            return {};
        
        stack<int> st;
        vector<bool> vis(numCourses,false);

        for(int i=0;i<numCourses;i++)
            if(!vis[i])
                dfs(adj,i,vis,st);
        
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        return ans;
    }
};