#include<bits/stdc++.h>
using namespace std;
#define int long long 
vector<int> find(int arr[],int n){
    unordered_map<int,int> mp;
    for(int i=0;i<n;i++){
        mp[arr[i]]++;
    }
    vector<int> ans;
    for(int i=0;i<n;i++){
        if(mp[arr[i]]==1)
            ans.push_back(arr[i]);
    }
    return ans;
}
int32_t	 main(){
        
}