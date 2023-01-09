//      Time Complexity :   O(N)
//      Space Complexity:   O(N)
#include<bits/stdc++.h>
#define si short int
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        map<char,si> hashmap;
        si count = 0;
        si ans = 0;
        for(si i=0;i<s.length();i++){
            if(hashmap.find(s[i]) != hashmap.end()){
                //  Found
                count = 0;
                i = hashmap[s[i]];
                hashmap.clear();
            }else{
                //  Not Found
                hashmap[s[i]] = i;
                count++;
            }
            ans = max(ans,count);
        }
        return (int)ans;
    }
};