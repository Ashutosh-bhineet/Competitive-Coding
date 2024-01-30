#include<bits/stdc++.h>
using namespace std;
int Bst(int n,vector<int> &dp){
    if(n==0)
        return dp[n]=1;
    if(n==1)
        return dp[n]=1;
    int ans=0;
    for(int i=1;i<=n;i++){
        ans+=Bst(i-1,dp)*Bst(n-i,dp);
    }
    return dp[n]=ans;
}
int main(){
    int n;
    cin>>n;
    vector<int> dp(n+1,-1);
    dp[0]=1;
    for(int i=1;i<=n;i++){
        int ans=0;
        for(int j=1;j<=i;j++){
            ans+=dp[j-1]*dp[i-j];
        }
        dp[i]=ans;
    }
    cout<<dp[n]<<endl;
}