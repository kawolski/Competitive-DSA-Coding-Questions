//      Time Complexity  : O(N)
//      Space Complexity : O(N)
class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int n = intervals.size();
        vector<vector<int>> ans;
        for(int i=0;i<n;i++){
            if(newInterval[1] < intervals[i][0]){
                ans.push_back(newInterval);
                for(;i<n;i++)
                    ans.push_back(intervals[i]);
                return ans;
            }
            else if(newInterval[0] > intervals[i][1])
                ans.push_back(intervals[i]);
            else
                newInterval = {min(newInterval[0],intervals[i][0]),max(newInterval[1],intervals[i][1])};
        }
        ans.push_back(newInterval);
        return ans;
    }
};