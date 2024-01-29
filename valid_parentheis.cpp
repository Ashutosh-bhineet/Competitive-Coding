#include <bits/stdc++.h>
using namespace std;
 void solve(string op,int open,int close,int n,vector<string>&ans){
        if(open==n && close==n){
            ans.push_back(op);
            return;
        }
        if(open<n)
            solve(op+"(",open+1,close,n,ans);
        if(close<open)
            solve(op+")",open,close+1,n,ans);
            
    }
    vector<string> generateParenthesis(int n) {
        int open=0;
        int close=0;
        vector<string> ans;
        string op="";
        solve(op,open,close,n,ans);
        return ans;
    }
int main(){
    int n;
    cin>>n;
    vector<string> a=generateParenthesis(n);
    for(string x:a)
        cout<<x<<endl;
}