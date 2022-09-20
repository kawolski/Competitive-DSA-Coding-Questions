#include<bits/stdc++.h>
using namespace std;
//      Time Complexity  : O(Log(N))
//      Space Complexity : O(1)
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int r = matrix.size();
        int c = matrix[0].size();
        //  Function to find nth element in 2-d matrix row-wise ordered
        function<int(int)> get_nth_element = [&](int num)->int{
            return (*(matrix[num/c].begin()+num%c));
        };
        //  Assume element not present
        bool ans = false;
        //  Binary Search Compute
        int low = 0;
        int high = r*c-1;
        
        while(low <= high){
            int mid = (low + high)>>1;
            int element = get_nth_element(mid);
            if(element < target)
                low = mid + 1;
            else if(element > target)
                high = mid - 1;
            else{
                ans = true;
                break;
            }
        }
        //  Return ans
        return ans;
    }
};