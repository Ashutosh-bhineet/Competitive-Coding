#include <bits/stdc++.h>
using namespace std;
int solve(int N,vector<int> &v){
    if(N==0){
        v.push_back(0);
        for(int i=v.size()-1;i>0;i--){
            cout<<v[i-1]-v[i]<<" ";
        }
        cout<<endl;
        v.pop_back();
        return 1;
    }
    if(N<0)
        return 0;
    v.push_back(N);
    int ans=solve(N-1,v)+solve(N-2,v)+solve(N-3,v);
    v.pop_back();
    return ans;
}
int main(){
    int n;
    cin>>n;
    vector<int> v;
    cout<<solve(n,v);
}