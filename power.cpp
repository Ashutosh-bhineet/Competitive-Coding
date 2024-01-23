#include <bits/stdc++.h>
using namespace std;
int solve(int a,int k){
    if(k==0){
        return 1;                     
    }
    int t=solve(a,k/2);
    t=t*t;
    if(k%2==0){
        return t;
    }
    else
        return t*a;
}
int bin_solve(int a,int n){
    int pro=1;
    while(n){
        if(n&1){
            pro*=a;
        }
        n=n>>1;
       a*=a;
    }
    return pro;
}
int main(){
    int a,k;
    cin>>a>>k;
    cout<<bin_solve(a,k);
}