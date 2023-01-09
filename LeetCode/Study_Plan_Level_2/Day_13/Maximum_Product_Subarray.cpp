//      Time Complexity :   O(N)
//      Space Complexity:   O(1)
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        //  Initialize
        int ans = nums[0];
        
        int mx = nums[0];
        int mn = nums[0];

        for(int i=1;i<n;i++){
            int a = mx * nums[i];
            int b = mn * nums[i];
            mx = max(max(a,b),nums[i]);
            mn = min(min(a,b),nums[i]);
            ans = max(ans,mx);
        }

        return ans;
    }
};