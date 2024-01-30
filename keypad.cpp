#include<bits/stdc++.h>
using namespace std;
vector<string> mp={"","ABC","DEF","GHI","JKL","MNO","PQRS","TUV","WXYZ"};
void solve(string s,int i,int n,string ans,vector<string> &substr){
    if(i==n){
        substr.push_back(ans);
        return ;
    }
    int t=s[i]-'0';
    if(t==0){
        solve(s,i+1,n,ans,substr);
        return;
    } 
    for(int j=0;j<mp[t].size();j++){
        solve(s,i+1,n,ans+mp[t][j],substr);
    }
}
vector<string> filter(string str,vector<string> contact){
    vector<string> st;
    vector<string> output;
    solve(str,0,str.size(),"",st);
    for(int i=0;i<st.size();i++){
        for(int j=0;j<contact.size();j++){
            if(contact[j].find(st[i])!=string::npos){
                output.push_back(contact[j]);
            }
        }
    }
    return output;
}
int main(){
   string s;
   cin>>s;
   int n=s.length();
   vector<string> substr;
    solve(s,0,n,"",substr);
    for(auto it:substr)
        cout<<it<<endl;
}