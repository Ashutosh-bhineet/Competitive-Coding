#include <bits/stdc++.h>
using namespace std;
int frogJump(int n, vector<int> &heights)
{
    vector<int> dp(n,0);
    dp[0]=0;
    for(int i=1;i<n;i++){
        int cost1=abs(heights[i-1]-heights[i])+dp[i-1];
        int cost2=INT_MAX;
        if(i>1)
        cost2=abs(heights[i-2]-heights[i])+dp[i-2];
        dp[i]=min(cost1,cost2);
    }
    return dp[n-1];
}
int main(){
    vector<int> arr={10,20,30,10};
    int n=4;
    vector<int> dp(n+1,-1);
}