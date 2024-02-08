#include<bits/stdc++.h>
using namespace std;
#define int long long int
const int N=1e5;
vector<int> gr[N];
int dp(int curr,int par){
    int ans=curr;
    for(auto child:gr[curr]){
        if(child!=par){
            ans+=dp(child,curr);
        }
    }
    return ans;
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
        cout<<dp(1,0);
}