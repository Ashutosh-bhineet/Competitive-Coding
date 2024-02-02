#include <bits/stdc++.h>
using namespace std;
int solve(int i,int j,int n,int m,vector<vector<int>> &dp){
    if(i==n-1 && j==m-1)
        return 1;
    if(i==n || j==m)
        return 0;
    if(dp[i][j]!=-1)
        return dp[i][j];
    return dp[i][j]=solve(i+1,j,n,m,dp)+solve(i,j+1,n,m,dp);
}
int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>> dp(n,vector<int>(m));
    for(int i=0;i<n;i++){
        dp[i][0]=1;
    }
    for(int j=0;j<m;j++){
        dp[0][j]=1;
    }
    for(int i=1;i<n;i++){
        for(int j=1;j<m;j++){
            dp[i][j]=dp[i-1][j]+dp[i][j-1];
        }
    }
    cout<<dp[n-1][m-1]<<endl;
}