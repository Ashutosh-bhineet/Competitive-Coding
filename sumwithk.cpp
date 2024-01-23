#include <bits/stdc++.h>
using namespace std;
int main(){
    int arr[]={1,3,2,1,4,1,3,2,1,1,2};
    int k=8;
    int n=11;
    int start=0;
    int sum=0;
    int ans=INT_MAX;
    for(int i=0;i<n;i++){
        if(sum<k){
            sum+=arr[i];
        }
        else if(sum>k){
            while(sum>k){
                sum-=arr[start++];
                if(sum==k){
                    ans=min(ans,i-start);
                }
            }
        }
            sum+=arr[i];
            ans=min(ans,i-start);
        }
    cout<<ans;
    }