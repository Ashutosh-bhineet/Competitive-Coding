#include <bits/stdc++.h>
using namespace std;
int solve(int n,vector<int> &dp){
    if(n==1)
        return 0;
    if(dp[n]!=-1)
        return dp[n];
    int a=INT_MAX,b=INT_MAX,c=INT_MAX;
    if(n%2==0)
        a=1+solve(n/2,dp);
    if(n%3==0)
        b=1+solve(n/3,dp);
    c=1+solve(n-1,dp);
    dp[n]=min(a,min(b,c));
    return dp[n];
}
	int minSteps(int N) 
	{ 
	    vector<int> dp(N+1,-1);
	    dp[0]=0;
	    dp[1]=0;
	    dp[2]=1;
	    dp[3]=1;
	    for(int i=4;i<=N;i++){
	        int div2=INT_MAX,div3=INT_MAX;
	        if(i%2==0){
	            div2=dp[i/2];
	        }
	        if(i%3==0)
	            div3=dp[i/3];
	       dp[i]=1+min(div2,min(div3,dp[i-1]));
	    }
	    return dp[N];
	    //return solve(N,dp);
	} 
int main(){
    int n;
    cin>>n;
    vector<int> dp(n+1,-1);
    cout<<minSteps(n);
}