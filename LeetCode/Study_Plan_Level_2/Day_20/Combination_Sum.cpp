//      Time Complexity  : O(2^N)
//      Space Complexity : O(2^N)
class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        
        vector<vector<int>> ans;
        int len = candidates.size();
        vector<int> temp;
        
        function<void(int,int)> dfs = [&](int index,int sum)->void{
            if(index >= len || sum > target)    return;
            
            if(sum == target){
                ans.push_back(temp);
                return;
            }
            
            //  Include current element
            temp.push_back(candidates[index]);
            //  Stay at current index
            dfs(index,sum+candidates[index]);
            //  Pop the pushed element
            temp.pop_back();
            
            //  Don't Include current element
            dfs(index+1,sum);
            
        };
        //  Function call with index 0 and sum 0
        dfs(0,0);
        
        return ans;
    }
};