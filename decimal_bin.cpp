#include <bits/stdc++.h>
using namespace std;
string dec_bin(int n){
    string s="";
    while(n>0){
        int rem=n%2;
        s.push_back(char(rem)+'0');
        n=n/2;
    }
    reverse(s.begin(),s.end());
    return s;
}
int main(){
    cout<<dec_bin(28);
}