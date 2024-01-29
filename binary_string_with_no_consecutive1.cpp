#include<bits/stdc++.h>
using namespace std;
void generate(string s,int ind,int n,vector<string> &ans){
    if(ind==n){
        ans.push_back(s);
        return ;
    }
    generate(s+'0',ind+1,n,ans);
    if(ind==0 || s[ind-1]!='1')
        generate(s+'1',ind+1,n,ans);
}
vector<string> gen(int n){
    if(n==1)
        return {"1","0"};
    vector<string> output;
    vector<string> subprob=gen(n-1);
    for(string s:subprob){
        if(s[s.size()-1]=='1')
            output.push_back(s+'0');
        else{
            output.push_back(s+'0');
            output.push_back(s+'1');
        }
    }
    return output;
}
int main(){
    int n;
    cin>>n;
    string s="";
    vector<string>ans;
    vector<string>ans2=gen(n);
    generate(s,0,n,ans);

    for(string t:ans){
        cout<<t<<" ";
    }
    cout<<endl;
    for(string t:ans2){
        cout<<t<<" ";
    }
}