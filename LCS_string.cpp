#include <bits/stdc++.h>
using namespace std;
int solve(string s1,string s2,int n,int m,vector<vector<int>> &dp){
    if(n==0 || m==0)
        return 0;
    if(dp[n][m]!=-1)
        return dp[n][m];
    if(s1[n-1]==s2[m-1])
        return dp[n][m]=1+solve(s1,s2,n-1,m-1,dp);
    return dp[n][m]=max(solve(s1,s2,n-1,m,dp),solve(s1,s2,n,m-1,dp));
}
int main(){
    string s1="abcdxyz";
    string s2="ghbfdxhzi";
    int n=s1.length();
    int m=s2.length();
    vector<vector<int>> dp(n+1,vector<int>(m+1));
    vector<vector<int>> dp2(n+1,vector<int>(m+1,-1));
    cout<<solve(s1,s2,n,m,dp2)<<endl;
    for(int i=0;i<=n;i++){
        for(int j=0;j<=m;j++){
            if(i==0 || j==0)
                dp[i][j]=0;
            else if(s1[i-1]==s2[j-1])
                dp[i][j]=1+dp[i-1][j-1];
            else
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
        }
    }
    string ans="";
    int i=n,j=m;
    while(i>0 && j>0){
        if(s1[i-1]==s2[j-1]){
            ans=s1[i-1]+ans;
            i--;
            j--;
        }
        else if(dp[i][j-1]>dp[i-1][j]){
            j--;
        }
        else{
            i--;
        }
    }
    cout<<ans<<" "<<endl;
    cout<<dp[n][m];
}