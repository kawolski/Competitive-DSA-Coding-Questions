//      Time Complexity  : O(N*M)
//      Space Complexity : O(1)
//      where   N = total strings
//              M = average length of string
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        //  Base case
        if(strs.size() == 0)
            return "";
        string lcpf = strs[0];
        for(int i=1;i<strs.size();i++){
            //  First character of string does not match
            if(lcpf[0] != strs[i][0])   return "";
            
            int j=0;
            
            for(;j<min(lcpf.size(),strs[i].size());j++)    if(strs[i][j] != lcpf[j])   break;
            
            lcpf = lcpf.substr(0,j);
        }
        //  Return the longest common prefix
        return lcpf;
    }
};