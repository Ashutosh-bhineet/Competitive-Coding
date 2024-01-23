#include <bits/stdc++.h>
using namespace std;
float square_root(int n,int k){
    float ans;
    int start=1,end=n;
    while(start<=end){
        int mid=start+(end-start)/2;
        if(mid*mid==n){
            ans=mid;
            break;
        }
        else if(mid*mid>n){
            end=mid-1;
        }
        else{
            start=mid+1;
        }
    }
    ans=end;
    float increment=0.1;
    for(int i=0;i<k;i++){
        while(ans*ans<=n){
            ans+=increment;
        }
        ans-=increment;
        increment/=10;
    }
    return ans;
}
int main(){
    int n,k;
    cin>>n>>k;
    cout<<square_root(n,k);
}