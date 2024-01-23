#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int sum=0;
    for(int i=0;i<n;i++){
        sum+=arr[i];
    }
    int sum2=0;
    for(int i=0;i<n;i++){
        if(i==0 || i==n-1){
            if(sum-arr[i]==0)
                cout<<i<<" ";
        }
        else{
            if(sum-sum2-arr[i]==sum2){
                cout<<i<<" ";
            }
        }
        sum2+=arr[i];
    }
}