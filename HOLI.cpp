#include<bits/stdc++.h>
using namespace std;
#define int long long int
int dfs(int src,int n,vector<vector<pair<int,int>>>&adj,vector<int>&vis,int &ans ){
    int size=1;
    vis[src]=1;
    for(auto it:adj[src]){
        if(!vis[it.first]){
            int count=dfs(it.first,n,adj,vis,ans);
            ans+=2*min(count,n-count)*it.second;
            size+=count;
        }
    }
    return size;
}
int32_t	 main(){
    int t;
    cin>>t;
    int number=0;
    while(t--){
        number++;
        int n;
        cin>>n;
        vector<vector<pair<int,int>>> adj(n);
        for(int i=0;i<n-1;i++){
            int x,y,z;
            cin>>x>>y>>z;
            adj[x-1].push_back({y-1,z});
            adj[y-1].push_back({x-1,z});
        }
        vector<int> visited(n,0);
        int ans=0;
        dfs(0,n,adj,visited,ans );
        cout<<"Case #"<<number<<": "<<ans<<endl;
    }
}
//give an array of integer we can change atmost one number so that the gcd of all number becomes maximum.return the index of changed element.
//Give an array of integer find the minimum product of the first and last element of a subsequence of size k in the array.