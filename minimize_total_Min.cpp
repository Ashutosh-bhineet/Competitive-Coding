#include <bits/stdc++.h>
using namespace std;
int solve(vector<int> arr,int i, int n){
    if(i>=n)
        return 0;
    int ans=0;
    for(int i=0;i<n-4;i++){
        ans+=min(solve(arr,i+1,n)+arr[i],min(solve(arr,i+2,n)+arr[i+1],solve(arr,i+3,n)+arr[i+1]));
    }
    return ans;
}
vector<int> min_time(vector<int> arr,int k){
    int n=arr.size();
    vector<int> dp(n);
    dp[0]=arr[0];
    dp[1]=arr[1];
    dp[2]=arr[2];
    for(int i=3;i<n;i++){
        dp[i]=arr[i]+min(dp[i-1],min(dp[i-2],dp[i-3]));
    }
    cout<<min(dp[n-1],min(dp[n-2],dp[n-3]));
}
int main(){
    vector<int> arr={3,2,1,1,2,3,1,3,2,1};
    int k=3;
    vector<int> ans=min_time(arr,k);
}