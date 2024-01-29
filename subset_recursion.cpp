#include<bits/stdc++.h>
using namespace std;
void solve(int i,int n,string s,vector<string> &ans,string str){
    if(i==n){
        ans.push_back(s);
        return ;
    }
    solve(i+1,n,s,ans,str);
    solve(i+1,n,s+str[i],ans,str);
}
int main(){
    int n;
    cin>>n;
    string s;
    cin>>s;
    vector<string> ans;
    solve(0,n,"",ans,s);
    for(string s:ans){
        cout<<s<<" ";
    }
}