#include <bits/stdc++.h>
using namespace std;
int main(){
    string a;
    cin>>a;
    int counta=0,countg=0;
    int ans=0;
    for(char c:a){
        if(c=='a'){
            counta++;
        }
        else if(c=='g'){
            ans+=counta;
        }
    }
    cout<<ans;
}