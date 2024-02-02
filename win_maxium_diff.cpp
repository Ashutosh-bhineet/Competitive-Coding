#include <bits/stdc++.h>
using namespace std;
int solve(int start,int end,vector<int> arr,vector<vector<int>> &dp){
    if(start>end)
        return 0;
    if(dp[start][end]!=-1)
        return dp[start][end];
    int ftake=arr[start]+min(solve(start+2,end,arr,dp),solve(start+1,end-1,arr,dp));
    int etake=arr[end]+min(solve(start+1,end-1,arr,dp),solve(start,end-2,arr,dp));
    return dp[start][end]=max(ftake,etake);
}
void print(vector<vector<int>> dp,int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<"----------------"<<endl;
}
int main(){
    int n=8;
    vector<int> arr={3,16,1,4,32,28,7,6};
    vector<vector<int>> dp(n,vector<int>(n));
    //cout<<solve(0,n-1,arr,dp)<<endl;
   for (int len = 1; len <= n; len++) {
        for (int i = 0; i <= n - len; i++) {
            int j = i + len - 1;
            if (i == j) {
                dp[i][j] = arr[i];
            } else if (i + 1 == j) {
                dp[i][j] = max(arr[i], arr[j]);
            } else {
                int ftake = arr[i] + min(dp[i + 2][j], dp[i + 1][j - 1]);
                int etake = arr[j] + min(dp[i + 1][j - 1], dp[i][j - 2]);
                dp[i][j] = max(ftake, etake);
            }
        }
    }
    cout<<dp[0][n-1];
}