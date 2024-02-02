#include <bits/stdc++.h>
using namespace std;
int solve(vector<int> price,int n,int i,int y,vector<vector<int>> &dp){
    if(i>n)
        return 0;
    if(dp[i][n]!=-1)
        return dp[i][n];
    int opt1=price[i]*(y)+solve(price,n,i+1,y+1,dp);
    int opt2=price[n]*(y)+solve(price,n-1,i,y+1,dp);
    return dp[i][n]=max(opt1,opt2);
}
void print(vector<vector<int>> dp,int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
}
int main(){
    vector<int> price={2,3,5,1,4};
    vector<vector<int>> dp1(5,vector<int>(5,-1));
    cout<<solve(price,4,0,1,dp1)<<endl;
    /* int n=5;
    vector<int> dp(n+1,-1);
    dp[0]=0;
    dp[1]=max(price[0],price[n-1]);
    for(int i=0;i<=n;i++){
        int opt1=price[0]*(i+1)+dp
    } */
    vector<vector<int>> dp(5,vector<int>(5,0));
    int n=5;
    int y=5;
    for(int i=0;i<n;i++){
        dp[i][i]=price[i]*y;
    }
    y--;
    for(int i=1;i<n;i++){
        for(int j=0;j<n-i;j++){
            dp[j][j+i]=max(dp[j][j+i-1]+price[j+i]*y,dp[j+1][j+i]+(price[j]*y));
        }
        y--;
    }
    print(dp,n);
    print(dp1,n);
    cout<<dp[0][n-1];
    //cout<<solve(price,4,0,1,dp);
}