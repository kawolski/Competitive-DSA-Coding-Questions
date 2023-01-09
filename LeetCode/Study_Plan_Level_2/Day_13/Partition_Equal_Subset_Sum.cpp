//      Time Complexity :   O(N^2)
//      Space Complexity:   O(N*sum)
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        //  Check for odd sum
        int sum = 0;
        for(int ele : nums)
            sum += ele;
        //  Odd Sum found : partition not possible
        if(sum&1)
            return false;
        //  Even sum : check if sum/2 can be formed
        int n = nums.size();
        vector<vector<bool>> dp(n+1,vector<bool>(sum/2 + 1,false));
        //  Initialization
        for(int i=0;i<n;i++)
            dp[i][0] = true;
        //  Compute
        for(int i=1;i<=n;i++){
            for(int j=1;j<=sum/2;j++){
                //  Exclude
                bool res = dp[i-1][j];
                if(nums[i-1] <= j){
                    //  Include
                    res = res || dp[i-1][j-nums[i-1]];
                }
                dp[i][j] = res;
            }
        }
        return dp[n][sum/2];
    }
};