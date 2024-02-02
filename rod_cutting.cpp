#include <bits/stdc++.h>
using namespace std;
int solve(vector<int> price,int length,int n){
        if(length<=0)
            return 0;
        int ans=0;
        for(int i=1;i<=n;i++){
            if(i<=length)
                ans=max(ans,price[i-1]+solve(price,length-i,n));
        }
        return ans;
        
    }
int main(){
    int n;
    cin>>n;
    vector<int> arr;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        arr.push_back(x);
    }
    cout<<solve(arr,8,8);
}