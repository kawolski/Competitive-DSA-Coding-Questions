//      Time Complexity  : O(N^2)
//      Space Complexity : ans -> O(N!) + heap -> O(N)
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        int len = nums.size();
        
        //  Lambda Function to solve recursively
        function<void(int)> perm = [&](int index)->void{
            //  If reached the end
            if(index == len){
                ans.push_back(nums);        //  Save the current permutation
                return;
            }
            
            for(int i=index;i<len;i++){
                swap(nums[index],nums[i]);  //  Swap nums[index] with nums[i]
                perm(index+1);              //  Move to next index 'perm'
                swap(nums[index],nums[i]);  //  Swap back
            }
            
        };
        
        //  Function call with index 0
        perm(0);
        
        return ans;
    }
};