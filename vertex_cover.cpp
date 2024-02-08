#include<bits/stdc++.h>
using namespace std;
#define int long long int
const int N=1e5+1;
vector<int> gr[N];
vector<vector<int>> memo(N,vector<int>(2,-1));
int dp(int curr,int par,int take){
    if(memo[curr][take]!=-1)
        return memo[curr][take];
    int ans=take;
    for(auto child:gr[curr]){
        if(child!=par){
            if(take){
                ans+=min(dp(child,curr,0),dp(child,curr,1));
            }
            else{
                ans+=dp(child,curr,1);
            }
        }
    }
    return memo[curr][take]=ans;
}
int32_t	 main(){
        int n;
        cin>>n;
        for(int i=0;i<n-1;i++){
            int x,y;
            cin>>x>>y;
            gr[x].push_back(y);
            gr[y].push_back(x);
        }
        cout<<min(dp(1,0,0),dp(1,0,1))<<endl;
}