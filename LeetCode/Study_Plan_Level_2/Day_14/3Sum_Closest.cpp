//      Time Complexity :   O(N^2)
//      Space Complexity:   O(1)
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        //  Helper variable
        int n = nums.size();
        //  Initialize
        int res = nums[0]+nums[1]+nums[2];
        //  Sort
        sort(nums.begin(),nums.end());
        //  Compute
        for(int i=0;i<n-2;i++){
            int s = i+1;
            int e = n-1;
            
            while(s < e){
                int sum = nums[i] + nums[s] + nums[e];
                if(abs(sum - target) < abs(res - target))
                    res = sum;
                if(sum < target)
                    s++;
                else
                    e--;
            }
        }
        //  Return result
        return res;
    }
};