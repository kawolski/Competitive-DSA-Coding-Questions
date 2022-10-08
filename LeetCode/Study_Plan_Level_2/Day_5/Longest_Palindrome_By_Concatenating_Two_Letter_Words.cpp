//      Time Complexity  : O(N)
//      Space Complexity : O(N)
class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        //  Keep count in map
        map<string,int> hashmap;
        for(string word : words)
            hashmap[word]++;
        
        int ans = 0;
        bool flag = false;
        
        for(auto ele : hashmap){
            
            //  The word
            string str = ele.first;
            
            //  Reverse of Word
            string r_str = ele.first;
            reverse(r_str.begin(),r_str.end());
            
            if(str == r_str){           //  Palindrome Word
                ans += ele.second/2;
                if(ele.second%2)
                    flag = true;
            }
            else{                       //  Non Palindrome Word
                if(hashmap.count(str)){
                    ans += min(ele.second,hashmap[r_str]);
                    hashmap.erase(r_str);
                }
            }
        }
        
        //  Convert pairs to character count
        ans = ans*4;
        //  Check for palindromic center element
        if(flag)
            ans += 2;
        
        return ans;
    }
};