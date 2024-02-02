#include <bits/stdc++.h>
using namespace std;
int solve(int n,int k,vector<int> &dp){
    if(n==0)
        return 1;
    if(dp[n]!=-1)
        return dp[n];
    int ans=0;
    for(int i=1;i<=k;i++){
        if(n-i>=0){
            ans+=solve(n-i,k,dp);
        }
    }
    return dp[n]=ans;
}
int main(){
    int n;
    cin>>n;
    int k;
    cin>>k;
    vector<int> dp(n+1,-1);
    dp[0]=1;
    dp[1]=1;
/*     for(int i=1;i<=n;i++){
        int ans=0;
        for(int j=1;j<=k;j++){
            if(i-j<0)
                break;
            ans+=dp[i-j];
        }
        dp[i]=ans;
    } */
    for(int i=2;i<=k;i++){
        dp[i]=2*dp[i-1];
    }
    for(int i=k+1;i<=n;i++){
        dp[i]=2*dp[i-1]-dp[i-k-1];
    }
    cout<<dp[n];
    //cout<<solve(n,k,dp);

}