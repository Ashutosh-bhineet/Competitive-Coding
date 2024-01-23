#include <bits/stdc++.h>
using namespace std;
#define int long long int
int check(int arr[],int height,int n,int m){
    int h=0;
    for(int i=0;i<n;i++){
        if(arr[i]>height)
            h+=arr[i]-height;
    }
    if(h>=m)
        return 1;
    return 0;
}
int solve(int arr[],int n,int m){
    int start=0;
    int end=arr[0];
    for(int i=0;i<n;i++){
        if(end<arr[i])
            end=arr[i];
    }
    int ans;
    while(start<=end){
        int mid=start+(end-start)/2;
        if(check(arr,mid,n,m)){
            ans=mid;
            start=mid+1;
        }
        else{
            end=mid-1;
        }
    }
    return ans;
}
int32_t main(){
    int n,m;
    cin>>n>>m;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<solve(arr,n,m);
}