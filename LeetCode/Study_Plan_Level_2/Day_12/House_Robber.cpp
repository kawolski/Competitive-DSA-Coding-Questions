//      Time Complexity     :   O(N)
//      Space Complexity    :   O(N)
class Solution {
public:
    int rob(vector<int>& nums) {
        //  Edge Case
        if(nums.size() == 1)    return nums[0];
        if(nums.size() == 2)    return max(nums[0],nums[1]);

        int n = nums.size();
        vector<int> dp(n);
        //  Initialization
        dp[n-1] = nums[n-1];
        dp[n-2] = max(nums[n-1],nums[n-2]);
        for(int i=n-3;i>=0;i--){
            dp[i] = max(nums[i]+dp[i+2],dp[i+1]);
        }
        return dp[0];
    }
};