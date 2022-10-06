//      Time Complexity  : O(N x M)
//      Space Complexity : O(M)
//      where
//      N = number of coins
//      M = amount
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount+1,INT_MAX);
        //  Initialization : Minimum coins required to make
        dp[0] = 0;
        
        for(int amt=1;amt<dp.size();amt++){
            for(int i=0;i<coins.size();i++){
                int coin = coins[i];
                //  If amount is non-negative and amount-coin is possible to make
                if(amt - coin >= 0 && dp[amt-coin] != INT_MAX){
                    //  Update the value by minimum yet found
                    dp[amt] = min(dp[amt-coin]+1,dp[amt]);
                }
            }
        }
        
        //  Return minimum number of coins requried to make the amount if possible
        return dp[amount] == INT_MAX ? -1 : dp[amount];
    }
};