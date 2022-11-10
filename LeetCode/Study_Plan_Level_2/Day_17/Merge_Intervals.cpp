//      Time Complexity  : O(N)
//      Space Complexity : O(N)
class Solution {
public:
    static bool compare(const vector<int> &a, const vector<int> &b){
        return a[0] < b[0];
    }
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(),compare);
        
        vector<vector<int>> ans;
        vector<int> current = intervals[0];
        for(int i=1;i<intervals.size();i++){
            if(current[1] >= intervals[i][0])
                current[1] = max(intervals[i][1],current[1]);
            else{
                ans.push_back(current);
                current = intervals[i];
            }
        }
        ans.push_back(current);
        return ans;
    }
};