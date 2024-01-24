#include <bits/stdc++.h>
using namespace std;
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount+1,INT_MAX);
        dp[0]=0;
        for(int i=1;i<=amount;i++){
            int ans=INT_MAX;
            for(int j=0;j<coins.size();j++){
                if(amount-coins[j]>=0){ 
                    int subprob=dp[amount-coins[j]];
                if(subprob!=INT_MAX)
                    ans=min(ans,subprob+1);
                }
            }
                dp[i]=ans;
        }
        if(dp[amount]==INT_MAX)
            return -1;
        return dp[amount];
    }
int main(){
    vector<int> coins={1,2,5};
    return coinChange(coins,11);
}   